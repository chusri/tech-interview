""" Generate text sequences using a statistical language model. """

import string
import tempfile
from numpy import array
from keras.layers import LSTM
from keras.layers import Dense
from keras.layers import Embedding
from keras.models import Sequential
from keras.preprocessing.text import Tokenizer
from keras.preprocessing.text import text_to_word_sequence

class TextGenerator:
    def __init__(self, training_data_file, sequence_length=51):
        """
        Initialize text generator object.

        Arguments:
        self
        training_data_file -- file containing training data
        sequence_length -- length of sequence of tokenized training data

        Returns:
        None
        """

        self.training_data_file = training_data_file
        self.sequence_length = sequence_length
        self.vocab_size = None

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

        X, Y = self._prepare_training_data()
        model = self._create_model(embedding_dim=embedding_dim,
                                   lstm_mem_cells=lstm_mem_cells,
                                   dense_neurons=dense_neurons)
        model.compile(loss='sparse_categorical_crossentropy',
                      optimizer='adam', metrics=['accuracy'])
        model.fit(X, Y, epochs=epochs, batch_size=batch_size)

    def _load_training_data(self):
        """
        Load training data to memory.

        Arguments:
        self

        Returns:
        training_data -- training data
        """

        with open(self.training_data_file, 'r') as file:
            training_data = file.read()
        return training_data

    def _tokenize_training_data(self, training_data):
        """
        Tokenize training data.

        Arguments:
        self

        Returns:
        tokens -- tokenized data
        """

        tokens = text_to_word_sequence(training_data)

        # Remove tokens that are not alphabetic
        tokens = [word for word in tokens if word.isalpha()]

        return tokens

    def _create_sequences(self, tokens):
        """
        Create sequences of length self.sequence_length from the tokens.

        Arguments:
        self
        tokens -- tokenized training data

        Returns:
        sequences -- list of sequences of length self.sequence_length each
        """

        sequences = list()
        for i in range(self.sequence_length, len(tokens)):
            sequence = tokens[i-self.sequence_length:i]
            line = ' '.join(sequence)
            sequences.append(line)

        return sequences

    def _encode_sequences(self, sequences):
        """
        Encode training sequences.

        Arguments:
        self
        sequences -- list of sequences of length self.sequence_length each

        Returns:
        encoded_sequences -- Encoded training sequences
        """

        tokenizer = Tokenizer()
        tokenizer.fit_on_texts(sequences)
        encoded_sequences = tokenizer.texts_to_sequences(sequences)
        self.vocab_size = len(tokenizer.word_index) + 1

        return encoded_sequences

    def _create_training_set(self, encoded_sequences):
        """
        Create training set by splitting encoded sequences into input (X) and
        output (Y).

        Arguments:
        self
        encoded_sequences -- Encoded training sequences

        Returns:
        X -- input sequence to the neural network
        Y -- output word
        """

        encoded_sequences = array(encoded_sequences)
        X, Y = encoded_sequences[:,:-1], encoded_sequences[:,-1]
        self.sequence_length = X.shape[1]

        return X, Y

    def _prepare_training_data(self):
        """
        Prepare data for training the model.

        Arguments:
        self

        Returns:
        X -- input sequence to the neural network
        Y -- output word
        """

        training_data = self._load_training_data()
        tokens = self._tokenize_training_data(training_data)
        sequences = self._create_sequences(tokens)
        encoded_sequences = self._encode_sequences(sequences)
        return self._create_training_set(encoded_sequences)

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
        model.add(Embedding(self.vocab_size, embedding_dim,
                            input_length=self.sequence_length))
        model.add(LSTM(lstm_mem_cells, return_sequences=True))
        model.add(LSTM(lstm_mem_cells))
        model.add(Dense(dense_neurons, activation='relu'))
        model.add(Dense(self.vocab_size, activation='softmax'))

        return model
