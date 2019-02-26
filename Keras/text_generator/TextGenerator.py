#!/home/ubuntu/anaconda3/envs/theano_p27/bin/python

""" Generate text sequences using a statistical language model. """

import sys
import argparse
from keras.layers import LSTM
from keras.layers import Dense
from keras.layers import Embedding
from keras.models import Sequential

sys.path.append('/home/ubuntu/efs/tech-interview/Keras/text_preprocessor/')
from TextPreProcessor import TextPreProcessor

class TextGenerator:
    def __init__(self, training_data_file, trained_model_file, word2int_map_file,
                 sequence_length=51):
        """
        Initialize text generator object.

        Arguments:
        self
        training_data_file -- file containing training data
        trained_model_file -- file where trained model will be saved
        word2int_map_file -- file containing words to integers mapping
        sequence_length -- length of sequence of tokenized training data

        Returns:
        None
        """

        self.text_preprocessor = TextPreProcessor(training_data_file,
                                                  word2int_map_file,
                                                  sequence_length)
        self.trained_model_file = trained_model_file

    def train(self, embedding_dim=50, lstm_mem_cells=100, dense_neurons=100,
              epochs=100, batch_size=128):
        """
        Train the neural network.

        Arguments:
        self
        embedding_dim -- Embedding dimensions
        lstm_mem_cells -- Number of LSTM memory cells
        dense_neurons -- Number of neurons in the fully-connected layer
        epochs -- Number of epochs to train
        batch_size -- Batch size

        Returns:
        """

        X, Y = self.text_preprocessor.text2sequence()
        model = self._create_model(embedding_dim=embedding_dim,
                                   lstm_mem_cells=lstm_mem_cells,
                                   dense_neurons=dense_neurons)
        model.compile(loss='sparse_categorical_crossentropy',
                      optimizer='adam', metrics=['accuracy'])
        model.fit(X, Y, epochs=epochs, batch_size=batch_size)

        # Save the trained model to file
        model.save(self.trained_model_file)

    def _create_model(self, embedding_dim=50, lstm_mem_cells=100,
                      dense_neurons=100):
        """
        Create a Keras training model.

        Arguments:
        self
        embedding_dim -- Embedding dimensions
        lstm_mem_cells -- Number of LSTM memory cells
        dense_neurons -- Number of neurons in the fully-connected layer

        Returns:
        model -- Keras training model
        """

        model = Sequential()
        model.add(Embedding(self.text_preprocessor.vocab_size, embedding_dim,
                            input_length=self.text_preprocessor.sequence_length))
        model.add(LSTM(lstm_mem_cells, return_sequences=True))
        model.add(LSTM(lstm_mem_cells))
        model.add(Dense(dense_neurons, activation='relu'))
        model.add(Dense(self.text_preprocessor.vocab_size, activation='softmax'))

        return model

def main():
    """
    Main thread of execution.

    Arguments:
    None

    Returns:
    None
    """

    text_generator = TextGenerator('republic.txt', 'republic_model.h5',
                                   'republic_word2int_map.pkl')
    text_generator.train(embedding_dim=50, lstm_mem_cells=100,
                         dense_neurons=100, epochs=100, batch_size=128)

if __name__ == '__main__':
    main()
