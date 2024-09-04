#!/usr/bin/env python
# coding: utf-8

import ROOT
import pandas as pd
import numpy as np
import gc
import tensorflow as tf

import math

N = 21

file = ROOT.TFile(f'training.root')

# Access the 'Detectors' tree
tree = file.Get("Detectors")

# Define the branches you want to extract
branches = ['detectorPositionX', 'detectorPositionY', 'eventNumber']

# Determine the total number of entries
total_entries = tree.GetEntries()

# Define the chunk size
chunk_size = 1500000000 # Adjust based on your system's RAM

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

# Define the branches you want to extract from the 'PrimaryParticle' tree
branches1 = ['energyPrimary', 'eventNumber', 'l', 'm', 'n']

# Determine the total number of entries in the 'PrimaryParticle' tree
total_entries1 = tree1.GetEntries()

# Initialize an empty DataFrame for the final result
df1 = pd.DataFrame()

for start in range(0, total_entries1, chunk_size):
    end = min(start + chunk_size, total_entries1)
    data_list1 = []

    # Loop over the entries in the current chunk
    for i in range(start, end):
        tree1.GetEntry(i)
        # Access branch data directly
        data1 = {branch: getattr(tree1, branch) for branch in branches1}
        data_list1.append(data1)

    # Convert the chunk to a DataFrame
    chunk_df1 = pd.DataFrame(data_list1)

    # Divide the 'energyPrimary' column by 1000 and convert to float16
    chunk_df1['energyPrimary'] = (chunk_df1['energyPrimary'] / 1000)
    chunk_df1['eventNumber'] = chunk_df1['eventNumber'].astype('int32')

    # Append the chunk DataFrame to the main DataFrame
    df1 = pd.concat([df1, chunk_df1], ignore_index=True)

    # Delete the chunk DataFrame and the data list to free up memory
    del chunk_df1
    del data_list1

    # Force the garbage collector to release unreferenced memory
    gc.collect()
    gc.collect()


df1 = df1[df1['eventNumber'].isin(df['eventNumber'])]
gc.collect()

df = df.drop_duplicates(subset=['eventNumber', 'detectorPositionX', 'detectorPositionY'])

gc.collect()

df = df.merge(df1[['eventNumber', 'energyPrimary']], on='eventNumber', how='left')

del df1
gc.collect()


# Convert columns back to float16
df['eventNumber'] = df['eventNumber'].astype('int32')
df['detectorPositionX'] = df['detectorPositionX'].astype('float16')
df['detectorPositionY'] = df['detectorPositionY'].astype('float16')

gc.collect()

import tensorflow as tf

groups = [group for _, group in df.groupby('eventNumber')]
labels = df.groupby('eventNumber')['energyPrimary'].first().values

def serialize_example(group, label):
    # Convert the 'detectorPositionX', 'detectorPositionY', 'duplicates_count' columns to floats
    detectorPositionX_floats = group['detectorPositionX'].values.astype(float)
    detectorPositionY_floats = group['detectorPositionY'].values.astype(float)
    label_float = float(label)

    feature = {
        'detectorPositionX': tf.train.Feature(float_list=tf.train.FloatList(value=detectorPositionX_floats)),
        'detectorPositionY': tf.train.Feature(float_list=tf.train.FloatList(value=detectorPositionY_floats)),
        'label': tf.train.Feature(float_list=tf.train.FloatList(value=[label_float]))
    }
    example_proto = tf.train.Example(features=tf.train.Features(feature=feature))
    return example_proto.SerializeToString()

# Write the dataset to a TFRecord file
with tf.io.TFRecordWriter(f'training_{N}.tfrecords') as writer:
    for group, label in zip(groups, labels):
        example = serialize_example(group, label)
        writer.write(example)

