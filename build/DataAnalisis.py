#!/usr/bin/env python
# coding: utf-8

import ROOT
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import gc
import math

ene = 3.0
N = 2
h = 12.5
testj = (round((ene - 3.0)/1.2)) + 1
ene_str = str(ene).replace('.', '_')

# Open the .root file
file = ROOT.TFile(f'test{N}_{testj}.root')

# Iterate over all items in the file
for key in file.GetListOfKeys():
    obj = key.ReadObj()
    # Check if the object is a tree
    if isinstance(obj, ROOT.TTree):
        tree_name = obj.GetName()
        print(f"Tree: {tree_name}")
        
        # List all branches in the tree
        branches = obj.GetListOfBranches()
        for branch in branches:
            print(f"  Branch: {branch.GetName()}")


# Access the 'Detectors' tree
tree = file.Get("Detectors")

# Define the branches you want to extract
branches = ['detectorPositionX', 'detectorPositionY', 'eventNumber']

# Determine the total number of entries
total_entries = tree.GetEntries()

# Define the chunk size
chunk_size = 15000000 # Adjust based on your system's RAM

# Initialize a list for the chunk DataFrames
dfs = []

# Process the tree in chunks
for start in range(0, total_entries, chunk_size):
    end = min(start + chunk_size, total_entries)
    data_list = []

    # Loop over the entries in the current chunk
    for i in range(start, end):
        tree.GetEntry(i)
        # Access branch data directly
        data = {branch: getattr(tree, branch) for branch in branches}
        data_list.append(data)

    # Convert the chunk to a DataFrame
    chunk_df = pd.DataFrame(data_list)

    # Convert the 'eventNumber' column to int32
    chunk_df['eventNumber'] = chunk_df['eventNumber'].astype('int32')

    # Add the chunk DataFrame to the list
    dfs.append(chunk_df)

    # Delete the data list to free up memory
    del data_list

    # Force the garbage collector to release unreferenced memory
    gc.collect()

# Concatenate all chunk DataFrames
df = pd.concat(dfs, ignore_index=True)

tree1 = file.Get("PrimaryParticle")
branches1 = ['energyPrimary', 'eventNumber']
total_entries1 = tree1.GetEntries()

df1 = pd.DataFrame()

for start in range(0, total_entries1, chunk_size):
    end = min(start + chunk_size, total_entries1)
    data_list1 = []

    for i in range(start, end):
        tree1.GetEntry(i)
        # Access branch data directly
        data1 = {branch: getattr(tree1, branch) for branch in branches1}
        data_list1.append(data1)

    chunk_df1 = pd.DataFrame(data_list1)
    chunk_df1['energyPrimary'] = (chunk_df1['energyPrimary'] / 1000)
    chunk_df1['eventNumber'] = chunk_df1['eventNumber'].astype('int32')

    # Append the chunk DataFrame to the main DataFrame
    df1 = pd.concat([df1, chunk_df1], ignore_index=True)

    del chunk_df1
    del data_list1

    gc.collect()

tree = file.Get("CircleCenter")
branches = ['centerX', 'centerY', 'eventNumber']
total_entries = tree.GetEntries()
chunk_size = 15000000 # Adjust based on your system's RAM
df2 = pd.DataFrame()

for start in range(0, total_entries, chunk_size):
    end = min(start + chunk_size, total_entries)
    data_list = []

    for i in range(start, end):
        tree.GetEntry(i)
        data = {branch: getattr(tree, branch) for branch in branches}
        data_list.append(data)

    chunk_df2 = pd.DataFrame(data_list)

    chunk_df2['centerX'] = chunk_df2['centerX']
    chunk_df2['centerY'] = chunk_df2['centerY']

    df2 = pd.concat([df2, chunk_df2], ignore_index=True)

    del chunk_df2
    del data_list

    gc.collect()

df1 = df1[df1['eventNumber'].isin(df['eventNumber'])]
df = df[df['eventNumber'].isin(df2['eventNumber'])]
gc.collect()

df = df.drop_duplicates(subset=['eventNumber', 'detectorPositionX', 'detectorPositionY'])

gc.collect()

df = df.merge(df1[['eventNumber', 'energyPrimary']], on='eventNumber', how='left')

del df1
gc.collect()

import joblib

# In the second notebook
poly_funcs = joblib.load('poly_funcs.pkl')

from scipy.stats import norm
def gaussian(x, A, mu, sigma, x0):
    return A * np.where(x < x0, norm.pdf(x, mu, sigma) / norm.pdf(mu, mu, sigma), 0)

def powerlaw1(x, a1, k1, x0):
    return (a1 * ((x) / (x0 + 1e-5)) ** -k1)

def combined_function(x, a1, k1, A, mu, sigma, x0):
    return np.where(x < x0, gaussian(x, A, mu, sigma, x0), powerlaw1(x, a1, k1, x0))

"""def create_combined_function(energy, poly_funcs):
    # Get the parameters from the polynomial functions
    a1 = 0.00055
    k1 = poly_funcs['k1'](energy)
    x0 = poly_funcs['x0'](energy)
    A = poly_funcs['A'](energy)
    mu = 9
    sigma = poly_funcs['sigma'](energy)

    def combined_function(x):
        return np.where(x < x0, gaussian(x, A, mu, sigma, x0), np.where(x <= 600, powerlaw1(x, a1, k1, x0), 0))
    return combined_function"""

def gaussian(x, A, mu, sigma, x0):
    return A * np.where(x < x0, norm.pdf(x, mu, sigma) / norm.pdf(mu, mu, sigma), 0)

def powerlaw1(x, a1, k1, x0):
    return (a1 * ((x) / (x0 + 1e-5)) ** -k1)

def powerlaw2(x, a2, k2, x1):
    return (a2 * ((x) / (x1 + 1e-5)) ** -k2)

def combined_function(x, x1=2.8e+02, a2=1.35421498e-05, k1=0.4, sigma=13, A=8.27906403e-02, x0=2.69759652e+01, k2=0.6, a1=1.64690604e-04, mu=0):
    return np.where(x < x0, 
                    gaussian(x, A, mu, sigma, x0), 
                    np.where(x < x1, 
                             powerlaw1(x, a1, k1, x0), 
                             powerlaw2(x, a2, k2, x1)))

from scipy.optimize import minimize
import sys
import multiprocessing as mp

def create_wrapper_function(ene):
    def negative_log_likelihood(params, x, y):
        a, b, r = params
        ri = np.sqrt((x - a)**2 + (y - b)**2) - r
        with np.errstate(invalid='ignore'):
            #combined_function = create_combined_function(ene, poly_funcs)
            probabilities = combined_function(ri)
        epsilon = sys.float_info.epsilon
        nll = -np.sum(np.log(probabilities + epsilon))
        return nll
    return negative_log_likelihood

negative_log_likelihood = create_wrapper_function(ene)

def process_event(event):
    # Filter the DataFrame for the current event
    event_data = df[df['eventNumber'] == event]
    
    ene_value = event_data["energyPrimary"].unique()[0]  # Replace with your actual energy value
    #negative_log_likelihood = create_wrapper_function(ene_value)

    # Check if the event exists in df2
    if event in df2['eventNumber'].values:
        # Get the "real center" for the current event from df2
        real_center = df2[df2['eventNumber'] == event][['centerX', 'centerY']].values[0]
        
        # Initial guess for the circle's radius (r)
        initial_guess_r = np.sqrt(np.mean((event_data['detectorPositionX'] - real_center[0])**2 +
                                          (event_data['detectorPositionY'] - real_center[1])**2))
        initial_guess = [real_center[0], real_center[1], initial_guess_r]

        # Minimize the negative log-likelihood
        result = minimize(
            negative_log_likelihood,
            initial_guess,
            args=(event_data['detectorPositionX'].values,
                  event_data['detectorPositionY'].values),
            method='L-BFGS-B',
            bounds=[(-650, 650), (-650, 650), (15, 1840)],
            options={'ftol':1e-2, 'gtol':1e-2, 'maxiter':1000}
        )

        # Check if the optimization was successful
        if result.success:
            # Return the optimized parameters along with the event number
            return {
                'eventNumber': event,
                'centerX': result.x[0],
                'centerY': result.x[1],
                'radius': result.x[2]
            }

# Get unique event numbers
unique_events = df['eventNumber'].unique()

# Create a pool of workers
with mp.Pool(mp.cpu_count()) as pool:
    # Process each event in parallel
    optimized_params_list = pool.map(process_event, unique_events)

# Filter out None results
optimized_params_list = [x for x in optimized_params_list if x is not None]

# Create a DataFrame from the list of optimized parameters
optimized_params_df = pd.DataFrame(optimized_params_list)

del df2
gc.collect()

df = pd.merge(df, optimized_params_df, on='eventNumber', how='left', suffixes=('', '_new'))

df.rename(columns={'centerX_new': 'centerX', 'centerY_new': 'centerY'}, inplace=True)

del optimized_params_df
gc.collect()

# Convert columns back to float16
df['eventNumber'] = df['eventNumber'].astype('int32')
df['detectorPositionX'] = df['detectorPositionX'].astype('float16')
df['detectorPositionY'] = df['detectorPositionY'].astype('float16')

gc.collect()

from scipy.optimize import fsolve

# Define the function
def calculate_half_angle(R, theta0=0.7):    
    def func(theta, R1=R, n=1.03, h=h, L=750):
        return L * np.tan(np.arcsin(n * np.sin(theta))) + (h / 2) * np.tan(theta) - R1

    theta_sol = fsolve(func, theta0, xtol=1e-4)

    return theta_sol[0]

def calculate_beta(cherenkov_angle, refractive_index):
    # Check if refractive index is non-zero to avoid division by zero
    if np.any(refractive_index == 0):
        raise ValueError("Refractive index cannot be zero.")

    # Calculate beta using the Cherenkov angle and refractive index
    beta = 1 / np.cos(cherenkov_angle) / refractive_index

    return beta

def calculate_beta_proton(energy_gev):
    # Rest mass energy of a proton in MeV
    rest_mass_energy_mev = 938.272

    # Convert energy from GeV to MeV
    energy_mev = energy_gev * 1000

    # Calculate the Lorentz factor
    gamma = 1 + (energy_mev / rest_mass_energy_mev)

    # Calculate beta using the Lorentz factor
    beta = np.sqrt(1 - 1 / gamma**2)

    return beta

def calculate_radius(ene, n=1.03, h=h, L=750):
    beta = calculate_beta_proton(ene)
    theta = np.arccos(1/(beta*n))

    return L * np.tan(np.arcsin(n * np.sin(theta))) + (h / 2) * np.tan(theta)

df["radius_gev"] = calculate_radius(df["energyPrimary"])
df["radius_gev"] = df["radius_gev"].astype('float16')

gc.collect()

df["residual"] = np.abs(np.sqrt((df["detectorPositionX"] - df["centerX"])**2 + (df["detectorPositionY"] - df["centerY"])**2) - df["radius_gev"]).astype('float16')
df = df[df['residual'].notna()]

variance_df = (df.groupby('eventNumber')['residual'].sum() / df.groupby('eventNumber').size()).reset_index().rename(columns={0: 'variance'})
good_eventNumbers = variance_df.loc[(variance_df['variance'] > 0) & (variance_df['variance'] < 50), 'eventNumber']
bad_eventNumbers = variance_df.loc[variance_df['variance'] > 100, 'eventNumber']
df_good = df.loc[df['eventNumber'].isin(good_eventNumbers)].copy()
df_bad = df.loc[df['eventNumber'].isin(bad_eventNumbers)].copy()

# Delete unused variables and original df
del df, good_eventNumbers, bad_eventNumbers
gc.collect()

import tensorflow as tf

# Group the DataFrame by 'eventNumber' and save each group as an element in a list
groups1 = [group for _, group in df_good.groupby('eventNumber')]
groups2 = [group for _, group in df_bad.groupby('eventNumber')]

# Get the labels (the 'eventNumber' column)
labels1 = df_good.groupby('eventNumber')['energyPrimary'].first().values
labels2 = df_bad.groupby('eventNumber')['energyPrimary'].first().values

def serialize_example(group, label):
    # Convert the 'detectorPositionX', 'detectorPositionY', 'duplicates_count' columns to floats
    detectorPositionX_floats = group['detectorPositionX'].values.astype(float)
    detectorPositionY_floats = group['detectorPositionY'].values.astype(float)
    centerX = group['centerX'].values.astype(float)
    centerY = group['centerY'].values.astype(float)
    label_float = float(label)

    feature = {
        'detectorPositionX': tf.train.Feature(float_list=tf.train.FloatList(value=detectorPositionX_floats)),
        'detectorPositionY': tf.train.Feature(float_list=tf.train.FloatList(value=detectorPositionY_floats)),
        'label': tf.train.Feature(float_list=tf.train.FloatList(value=[label_float])),
    }
    example_proto = tf.train.Example(features=tf.train.Features(feature=feature))
    return example_proto.SerializeToString()

# Write the dataset to a TFRecord file
with tf.io.TFRecordWriter(f'good{ene_str}({N}).tfrecords') as writer:
    for group, label in zip(groups1, labels1):
        example = serialize_example(group, label)
        writer.write(example)

with tf.io.TFRecordWriter(f'bad{ene_str}({N}).tfrecords') as writer:
    for group, label in zip(groups2, labels2):
        example = serialize_example(group, label)
        writer.write(example)

df_good.loc[:, "beta_hat"] = calculate_beta(df_good["radius"].apply(calculate_half_angle), 1.05)

df_bad.loc[:, "beta_hat"] = calculate_beta(df_bad["radius"].apply(calculate_half_angle), 1.05)

df_good = df_good[['beta_hat', "eventNumber"]]
df_bad = df_bad[['beta_hat', "eventNumber"]]

df_good.to_csv(f'df{ene_str}_good{N}.csv', index=False)
df_bad.to_csv(f'df{ene_str}_bad{N}.csv', index=False)

