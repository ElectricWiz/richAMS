#!/usr/bin/env python
# coding: utf-8

import ROOT
import pandas as pd
import numpy as np
import gc
import math

N = 16

file = ROOT.TFile(f'training.root')

tree = file.Get("Detectors")
branches = ['detectorPositionX', 'detectorPositionY', 'eventNumber']
total_entries = tree.GetEntries()
chunk_size = 15000000 # Adjust based on your system's RAM
dfs = []

for start in range(0, total_entries, chunk_size):
    end = min(start + chunk_size, total_entries)
    data_list = []

    for i in range(start, end):
        tree.GetEntry(i)
        data = {branch: getattr(tree, branch) for branch in branches}
        data_list.append(data)

    chunk_df = pd.DataFrame(data_list)
    chunk_df['eventNumber'] = chunk_df['eventNumber'].astype('int32')
    dfs.append(chunk_df)
    del data_list

    gc.collect()

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
        data1 = {branch: getattr(tree1, branch) for branch in branches1}
        data_list1.append(data1)

    chunk_df1 = pd.DataFrame(data_list1)
    chunk_df1['energyPrimary'] = (chunk_df1['energyPrimary'] / 1000)
    chunk_df1['eventNumber'] = chunk_df1['eventNumber'].astype('int32')

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

df = df.merge(df1[['eventNumber', 'energyPrimary']], on='eventNumber', how='left').merge(df2[['eventNumber', 'centerX', 'centerY']], on='eventNumber', how='left')

del df1
gc.collect()

del df2
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
    centerX = group['centerX'].values.astype(float)
    centerY = group['centerY'].values.astype(float)
    label_float = float(label)

    feature = {
        'detectorPositionX': tf.train.Feature(float_list=tf.train.FloatList(value=detectorPositionX_floats)),
        'detectorPositionY': tf.train.Feature(float_list=tf.train.FloatList(value=detectorPositionY_floats)),
        'label': tf.train.Feature(float_list=tf.train.FloatList(value=[label_float])),
        'centerX': tf.train.Feature(float_list=tf.train.FloatList(value=centerX)),
        'centerY': tf.train.Feature(float_list=tf.train.FloatList(value=centerY))
    }
    example_proto = tf.train.Example(features=tf.train.Features(feature=feature))
    return example_proto.SerializeToString()

# Write the dataset to a TFRecord file
with tf.io.TFRecordWriter(f'training_{N}.tfrecords') as writer:
    for group, label in zip(groups, labels):
        example = serialize_example(group, label)
        writer.write(example)

