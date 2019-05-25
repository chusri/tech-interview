#!/home/ubuntu/anaconda3/envs/tensorflow_p36/bin/python

""" Neural Collaborative Filtering based Recommendation System for movies, books etc. """

import pandas as pd
from keras.layers import merge
from keras.layers import Dense
from keras.layers import Flatten
from keras.layers import Dropout
from keras.layers import Embedding
from keras.optimizers import Adam
from keras.models import Sequential
from sklearn.model_selection import train_test_split

class RecommendationSystem:
    def __init__(self, training_data_file, trained_model_file, num_latent_factors=64):
        """
        Initialize Recommendation System object.

        Arguments:
        self
        training_data_file -- file containing training data
        trained_model_file -- file where trained model will be saved
        num_latent_factors -- number of latent factors for users and items

        Returns:
        None
        """

        self.train_data, self.test_data = self._preprocess_training_data(training_data_file)
        self.trained_model_file = trained_model_file
        self.num_latent_factors = num_latent_factors

    def train(self, epochs=100, batch_size=128):
        """
        Train the neural network.

        Arguments:
        self
        epochs -- number of epochs to train
        batch_size -- batch size

        Returns:
        None
        """

        num_users = len(self.train_data.user_id.unique())
        num_items = len(self.train_data.item_id.unique())

        model = self._create_training_model(num_users, num_items)
        model.summary()
        model.compile(loss='mean_absolute_error', optimizer='adam', metrics=['accuracy'])
        model.fit([self.train_data.user_id, self.train_data.item_id], self.train_data.rating,
                  epochs=epochs, batch_size=batch_size)

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

    def _create_training_model(self, num_users, num_items, dropout=0.2):
        """
        Create a Keras training model.

        Arguments:
        self
        num_users -- number of users
        num_items -- number of items
        dropout -- dropout value

        Returns:
        model -- Keras training model
        """

        user_model = self._create_embedding_model(num_users, self.num_latent_factors,
                                                  'user_embedding', 'user_flatten')
        item_model = self._create_embedding_model(num_items, self.num_latent_factors,
                                                  'item_embedding', 'item_flatten')
        model = Sequential()
        model.add(merge([user_model, item_model], mode='concat', name='concat'))
        model.add(Dropout(dropout, name='dropout_2'))
        model.add(Dense(200, name='fully_connected_1'))
        model.add(Dropout(dropout, name='dropout_3'))
        model.add(Dense(100, name='fully_connected_2'))
        model.add(Dropout(dropout, name='dropout_4'))
        model.add(Dense(50, name='fully_connected_3'))
        model.add(Dropout(dropout, name='dropout_5'))
        model.add(Dense(20, name='fully_connected_4', activation='relu'))
        model.add(Dense(1, name='activation', activation='relu'))

        return model

    def _create_embedding_model(self, input_dim, output_dim, embedding_name, flatten_name,
                                dropout=0.2):
        """
        Create a Keras embedding model.

        Arguments:
        self
        input_dim -- input dimension
        output_dim -- output dimension
        embedding_name -- name of embedding layer
        flatten_name -- name of flatten layer
        dropout -- dropout value

        Returns:
        model -- Keras embedding model
        """

        model = Sequential()
        model.add(Embedding(input_dim+1, output_dim, name=embedding_name))
        model.add(Flatten(name=flatten_name))
        model.add(Dropout(dropout, name='dropout_1'))

        return model

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
