""" Generate text sequences using a statistical language model. """

import string
import tempfile
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

        return encoded_sequences
