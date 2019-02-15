""" Generate text sequences using a statistical language model. """

import string

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
        Clean and tokenize training data.
        1. Replace '-' with a white space so we can split words better
        2. Split words based on white space
        3. Remove all punctuation from words to reduce the vocabulary size
           (e.g. 'What?' becomes 'What')
        4. Remove all words that are not alphabetic to remove standalone
           punctuation tokens
        5. Normalize all words to lowercase to reduce the vocabulary size

        Arguments:
        self

        Returns:
        tokens -- tokenized data
        """

        training_data = training_data.replace('--', ' ')
        tokens = training_data.split()

        # Remove all punctuation from words to reduce the vocabulary size
        table = string.maketrans('', '')
        tokens = [word.translate(table, string.punctuation) for word in tokens]

        # Remove tokens that are not alphabetic
        tokens = [word for word in tokens if word.isalpha()]

        tokens = [word.lower() for word in tokens]
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
