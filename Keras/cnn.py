#!/home/ubuntu/wspace-2/anaconda2/bin/python

""" Implement a simple CNN in Keras. """

import numpy as np
from keras.datasets import mnist
from keras.utils import np_utils
from keras.models import Sequential
from keras.layers import Convolution2D, MaxPooling2D
from keras.layers import Dense, Dropout, Activation, Flatten

def preProcessData():
    """ Pre-process the training and test datasets. """

    # Load pre-shuffled MNIST data into train and test sets
    (X_train, y_train), (X_test, y_test) = mnist.load_data()

    # Reshape tensors to include 1 input channel
    X_train = X_train.reshape(X_train.shape[0], 1, 28, 28)
    X_test = X_test.reshape(X_test.shape[0], 1, 28, 28)

    # Convert data type and normalize values
    X_train = X_train.astype('float32')
    X_test = X_test.astype('float32')
    X_train /= 255
    X_test /= 255

    # Convert 1-dim class tensors to 10-dim class tensors
    Y_train = np_utils.to_categorical(y_train, 10)
    Y_test = np_utils.to_categorical(y_test, 10)

    return X_train, Y_train, X_test, Y_test

def model():
    """ Define a simple CNN model architecture. """

    model = Sequential()

    # CNN input layer
    model.add(Convolution2D(32, (3, 3), activation='relu', input_shape=(1, 28, 28)))

    return model 

def main():
    X_train, Y_train, X_test, Y_test = preProcessData()
    cnnModel = model()

    print cnnModel.output_shape

if __name__ == '__main__':
    main()
