#!/usr/bin/env python
# coding: utf-8

# # Import Required Libraries
# Import the necessary libraries, including pandas, NumPy, TensorFlow, and Keras.

# In[ ]:


# NumPy is used for numerical operations
import numpy as np

# Keras is a user-friendly neural network library written in Python
from tensorflow import keras


# # Load and Inspect the Data
# Load the training.csv file into a DataFrame and inspect its structure and contents.

# In[ ]:


import tensorflow as tf

def parse_proto(proto):
    columns = {
        'detectorPositionX': tf.io.VarLenFeature(tf.float32),
        'detectorPositionY': tf.io.VarLenFeature(tf.float32),
        'centerX': tf.io.VarLenFeature(tf.float32),
        'centerY': tf.io.VarLenFeature(tf.float32),
        'label': tf.io.FixedLenFeature([], tf.float32)
    }
    return tf.io.parse_single_example(proto, columns)
    
@tf.function(experimental_compile=True)
def convert_and_flatten(parsed_features):
    x = tf.reshape(tf.sparse.to_dense(parsed_features['detectorPositionX']), [-1])
    y = tf.reshape(tf.sparse.to_dense(parsed_features['detectorPositionY']), [-1])
    centerX = tf.reshape(tf.sparse.to_dense(parsed_features['centerX']), [-1])
    centerY = tf.reshape(tf.sparse.to_dense(parsed_features['centerY']), [-1])
    return x, y, centerX, centerY

@tf.function(experimental_compile=True)
def create_indices(x, y, centerX, centerY):
    indices_xy = tf.stack([tf.cast((x+680)/8.5, tf.int32) - 1, tf.cast((y+680)/8.5, tf.int32) - 1], axis=1)
    indices_center = tf.stack([tf.cast((centerX+680)/8.5, tf.int32) - 1, tf.cast((centerY+680)/8.5, tf.int32) - 1], axis=1)
    return indices_xy, indices_center

@tf.function(experimental_compile=True)
def update_image(indices_xy, indices_center, x, centerX):
    image = tf.zeros((156, 156), dtype=tf.float32)
    updates_xy = tf.ones_like(x)
    updates_center = -tf.ones_like(centerX)
    image = tf.tensor_scatter_nd_update(image, indices_xy, updates_xy)
    image = tf.tensor_scatter_nd_update(image, indices_center, updates_center)
    return tf.reshape(image, [156, 156, 1])

def _parse_function(proto):
    parsed_features = parse_proto(proto)
    x, y, centerX, centerY = convert_and_flatten(parsed_features)
    indices_xy, indices_center = create_indices(x, y, centerX, centerY)
    image = update_image(indices_xy, indices_center, x, centerX)
    return image, parsed_features['label'], tf.size(x) >= 3


"""def parse_proto(proto):
    columns = {
        'detectorPositionX': tf.io.VarLenFeature(tf.float32),
        'detectorPositionY': tf.io.VarLenFeature(tf.float32),
        'label': tf.io.FixedLenFeature([], tf.float32)
    }
    return tf.io.parse_single_example(proto, columns)

@tf.function(experimental_compile=True)
def convert_and_flatten(parsed_features):
    x = tf.reshape(tf.sparse.to_dense(parsed_features['detectorPositionX']), [-1])
    y = tf.reshape(tf.sparse.to_dense(parsed_features['detectorPositionY']), [-1])
    return x, y

@tf.function(experimental_compile=True)
def create_indices(x, y):
    indices_xy = tf.stack([tf.cast((x+680)/8.5, tf.int32) - 1, tf.cast((y+680)/8.5, tf.int32) - 1], axis=1)
    return indices_xy

@tf.function(experimental_compile=True)
def update_image(indices_xy, x):
    image = tf.zeros((156, 156), dtype=tf.float32)
    updates_xy = tf.ones_like(x)
    image = tf.tensor_scatter_nd_update(image, indices_xy, updates_xy)
    return tf.reshape(image, [156, 156, 1])

def _parse_function(proto):
    parsed_features = parse_proto(proto)
    x, y = convert_and_flatten(parsed_features)
    indices_xy = create_indices(x, y)
    image = update_image(indices_xy, x)
    return image, parsed_features['label'], tf.size(x) >= 3"""

# Read the tfrecords file
dataset = tf.data.TFRecordDataset( ["tfrecords/training_{}.tfrecords".format(i) for i in range(0, 21)])

# Map the parse function to each record
dataset = dataset.map(_parse_function, num_parallel_calls=tf.data.experimental.AUTOTUNE)

# Filter out entries where the length of x is less than 3
dataset = dataset.filter(lambda image, label, include: include)

# Remove the 'include' field from the dataset
dataset = dataset.map(lambda image, label, include: (image, label))


# In[ ]:


# Count the total number of examples in the dataset
total_size = sum(1 for _ in dataset)

# Calculate the size of each subset
train_size = int(0.99 * total_size)
val_size = int(0.01 * total_size)  # validation size
test_size = total_size - train_size - val_size  # test size 


# In[ ]:
batch_size = 32
num_epochs = 25

train_dataset = dataset.take(train_size).cache().shuffle(256, reshuffle_each_iteration=True).repeat(num_epochs).batch(batch_size)
val_dataset = dataset.skip(val_size).batch(batch_size)

train_dataset = train_dataset.prefetch(tf.data.experimental.AUTOTUNE)
val_dataset = val_dataset.prefetch(tf.data.experimental.AUTOTUNE)


# 

# # Create the Convolutional Neural Network
# Create a CNN model with 3 convolutional layers, two dense layers, and a final layer of one neuron to predict the value of the energyPrimary.

# In[ ]:


# Importing the required layers for the Convolutional Neural Network
from tensorflow.keras.layers import Conv2D, MaxPooling2D, Flatten, Dense, Dropout, add, Activation, Input, concatenate, LeakyReLU
from tensorflow.keras import mixed_precision, Model, regularizers

# Define the L2 regularizer
l2_reg = regularizers.l2(0.001)

# Set the policy to 'mixed_float16'
mixed_precision.set_global_policy('mixed_float16')

def inception_module(x, filters):
    # 1x1 conv
    conv1 = Conv2D(int(filters*.25), (1, 1), padding='same')(x)
    conv1 = LeakyReLU()(conv1)

    # 1x1 conv -> 3x3 conv
    conv2 = Conv2D(filters, (1, 1), padding='same')(x)
    conv2 = LeakyReLU()(conv2)
    conv2 = Conv2D(int(filters*.5), (3, 3), padding='same')(conv2)
    conv2 = LeakyReLU()(conv2)

    # 1x1 conv -> 5x5 conv
    conv3 = Conv2D(filters, (1, 1), padding='same')(x)
    conv3 = LeakyReLU()(conv3)
    conv3 = Conv2D(int(filters*.25), (5, 5), padding='same')(conv3)
    conv3 = LeakyReLU()(conv3)

    return concatenate([conv1, conv2, conv3], axis=-1)

# Define the input shapfilters
input_layer = Input(shape=(156, 156, 1))

# Add the new Conv2D layers
x = Conv2D(8, (7, 7), strides=(5, 5))(input_layer)
x = LeakyReLU()(x)
x = Conv2D(8, (5, 5), strides=(3, 3), padding="same")(x)
x = LeakyReLU()(x)

x = inception_module(x, 8)
x = inception_module(x, 16)

x = inception_module(x, 16)

x = Conv2D(24, (3, 3))(x)
x = LeakyReLU()(x)

x = Dropout(0.15)(x)

x = Flatten()(x)

# Add your dense layers here
# For example:
x = Dense(24)(x)
x = LeakyReLU()(x)
x = Dense(24)(x)
x = LeakyReLU()(x)
x = Dense(48)(x)
x = LeakyReLU()(x)
x = Dense(8)(x)
x = LeakyReLU()(x)
x = Dense(1, dtype='float32')(x)

model = Model(inputs=input_layer, outputs=x)

# Print the summary of the model to check the number of parameters and the structure
model.summary()
# Print the summary of the model to check the number of parameters and the structure


# # Train the Convolutional Neural Network
# Train the CNN model using the prepared training data.

# In[ ]:


# Importing the required library for the model compilation and training
from tensorflow.keras.optimizers import Adam
from tensorflow.keras.models import load_model
from tensorflow.keras.callbacks import EarlyStopping, LearningRateScheduler, ModelCheckpoint, TensorBoard
from datetime import datetime
import gc

def lr_schedule(epoch, lr):
    if epoch == 4:
        return 0.0001
    elif epoch == 12 :  # 3 epochs after the first change
        return 0.00001
    elif epoch == 18:  # 3 epochs after the first change
        return 0.000001
    return lr

lr_callback = LearningRateScheduler(lr_schedule)
optimizer = Adam(clipnorm=0.3)

model.compile(optimizer=optimizer, loss='mean_absolute_error', metrics=['mean_absolute_percentage_error'], jit_compile=True)

history = model.fit(train_dataset, epochs=num_epochs, validation_data=val_dataset, verbose=1, steps_per_epoch = train_size // batch_size, callbacks=[lr_callback])

# Save the trained model for future use
model.save('cnn_Center.keras')

model.save('cnn2cm_NoCenter.h5')


import matplotlib.pyplot as plt
import seaborn as sns

sns.set_theme()

plt.figure(figsize=(12, 6))
plt.plot(history.history['loss'], label='Error de Entrenamiento')
plt.plot(history.history['val_loss'], label='Error de Validación')
plt.title('Error Contra Epoca de Entrenamiento')
plt.xlabel('Epoca')
plt.ylabel(r'Error [$\beta$]')
plt.legend()
