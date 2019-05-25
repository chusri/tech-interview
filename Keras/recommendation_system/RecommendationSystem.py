#!/home/ubuntu/anaconda3/envs/tensorflow_p36/bin/python

""" Neural Collaborative Filtering based Recommendation System for movies, books etc. """

import pandas as pd
from sklearn.model_selection import train_test_split

class RecommendationSystem:
    def __init__(self, training_data_file, trained_model_file):
        """
        Initialize Recommendation System object.

        Arguments:
        self
        training_data_file -- file containing training data
        trained_model_file -- file where trained model will be saved

        Returns:
        None
        """

        self.train_data, self.test_data = self._preprocess_training_data(training_data_file)
        self.trained_model_file = trained_model_file

    def _preprocess_training_data(self, training_data_file):
        """
        Read the training dataset from file and preprocess it.

        Arguments:
        self
        training_data_file -- file containing training data

        Returns:
        Pandas dataframes containing train and test datasets
        """

        dataset = pd.read_csv(training_data_file, sep='\t',
                              names='user_id,item_id,rating,timestamp'.split(','))

        # Assign a unique user_id between (0, #users)
        dataset.user_id = dataset.user_id.astype('category').cat.codes.values
        # Assign a unique item_id between (0, #items)
        dataset.item_id = dataset.item_id.astype('category').cat.codes.values

        return train_test_split(dataset, test_size=0.2)

def main():
    """
    Main thread of execution.

    Arguments:
    None

    Returns:
    None
    """

    pass

if __name__ == '__main__':
    main()
