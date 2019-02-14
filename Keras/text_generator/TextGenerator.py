""" Generate text sequences using a statistical language model. """

class TextGenerator:
    def __init__(self, training_data_file):
        """
        Initialize text generator object.

        Arguments:
        self
        training_data_file -- file containing the training data

        Returns:
        None
        """

        self.training_data_file = training_data_file

    def load_training_data(self):
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
