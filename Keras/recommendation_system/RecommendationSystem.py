#!/home/ubuntu/anaconda3/envs/tensorflow_p36/bin/python

""" Neural Collaborative Filtering based Recommendation System for movies, books etc. """

import pandas as pd
import matplotlib.pyplot as plt
from keras import Model
from keras.layers import Input
from keras.layers import Dense
from keras.layers import Flatten
from keras.layers import Dropout
from keras.layers import Embedding
from keras.layers import concatenate
from keras.optimizers import Adam
from keras.utils.vis_utils import plot_model
from sklearn.model_selection import train_test_split

class RecommendationSystem:
    def __init__(self, training_data_file, trained_model_file, model_plot_file='model_plot.png',
                 model_accuracy_file='model_accuracy.png', model_loss_file='model_loss.png',
                 num_latent_factors=64):
        """
        Initialize Recommendation System object.

        Arguments:
        self
        training_data_file -- file containing training data
        trained_model_file -- file where trained model will be saved
        model_plot_file -- file where model plot will be saved
        model_accuracy_file -- file where model accuracy plot will be saved
        model_loss_file -- file where model loss plot will be saved
        num_latent_factors -- number of latent factors for users and items

        Returns:
        None
        """

        self.num_users, self.num_items, self.train_data, self.test_data = \
                                        self._preprocess_training_data(training_data_file)
        self.trained_model_file = trained_model_file
        self.model_plot_file = model_plot_file
        self.model_accuracy_file = model_accuracy_file
        self.model_loss_file = model_loss_file
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

        model = self._create_training_model(self.num_users, self.num_items)
        model.compile(loss='mean_absolute_error', optimizer='adam', metrics=['accuracy'])
        history = model.fit([self.train_data.user_id.values, self.train_data.item_id.values],
                            self.train_data.rating.values, epochs=epochs, batch_size=batch_size)
        model.save(self.trained_model_file)

        plot_model(model, to_file=self.model_plot_file, show_shapes=True, show_layer_names=True)
        self._visualize_model_accuracy(history)
        self._visualize_model_loss(history)

    def _visualize_model_accuracy(self, history):
        """
        Visualize model accuracy.

        Arguments:
        self
        history -- record of training loss values and metrics values at successive epochs

        Returns:
        None
        """

        plt.plot(history.history['acc'])
        plt.title('Model Accuracy')
        plt.ylabel('Accuracy')
        plt.xlabel('Epochs')
        plt.legend(['Train'], loc='upper left')
        plt.savefig(self.model_accuracy_file)

    def _visualize_model_loss(self, history):
        """
        Visualize model loss.

        Arguments:
        self
        history -- record of training loss values and metrics values at successive epochs

        Returns:
        None
        """

        plt.plot(history.history['loss'])
        plt.title('Model Loss')
        plt.ylabel('Loss')
        plt.xlabel('Epochs')
        plt.legend(['Train'], loc='upper left')
        plt.savefig(self.model_loss_file)

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

        num_users = len(dataset.user_id.unique())
        num_items = len(dataset.item_id.unique())
        train_data, test_data = train_test_split(dataset, test_size=0.2)

        return num_users, num_items, train_data, test_data

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

        user_input, user_vector = self._create_embedding('user', num_users, self.num_latent_factors)
        item_input, item_vector = self._create_embedding('item', num_items, self.num_latent_factors)

        concat_vector = concatenate([user_vector, item_vector], name='concat')
        dropout_1 = Dropout(dropout, name='dropout_1')(concat_vector)
        dense_1 = Dense(200, name='fully_connected_1')(dropout_1)
        dropout_2 = Dropout(dropout, name='dropout_2')(dense_1)
        dense_2 = Dense(100, name='fully_connected_2')(dropout_2)
        dropout_3 = Dropout(dropout, name='dropout_3')(dense_2)
        dense_3 = Dense(50, name='fully_connected_3')(dropout_3)
        dropout_4 = Dropout(dropout, name='dropout_4')(dense_3)
        dense_4 = Dense(20, name='fully_connected_4', activation='relu')(dropout_4)
        result = Dense(1, name='activation', activation='relu')(dense_4)

        return Model([user_input, item_input], result)

    def _create_embedding(self, name, input_dim, output_dim, dropout=0.2):
        """
        Create a Keras embedding.

        Arguments:
        self
        name -- embedding name
        input_dim -- input dimension
        output_dim -- output dimension
        dropout -- dropout value

        Returns:
        input_vector -- input vector
        output_vector -- embedding vector
        """

        input_vector = Input(shape=[1], name=name+'_input')
        embedding = Embedding(input_dim+1, output_dim, input_length=1,
                              name=name+'_embedding')(input_vector)
        output_vector = Flatten(name=name+'_flatten')(embedding)
        output_vector = Dropout(dropout, name=name+'_dropout')(output_vector)

        return input_vector, output_vector

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
