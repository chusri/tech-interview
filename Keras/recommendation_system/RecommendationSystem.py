#!/home/ubuntu/anaconda3/envs/tensorflow_p36/bin/python

""" Deep Learning based Recommendation System for movies, books etc. """

class RecommendationSystem:
    def __init__(self, training_data_file=None, trained_model_file=None):
        """
        Initialize Recommendation System object.

        Arguments:
        self
        training_data_file -- file containing training data
        trained_model_file -- file where trained model will be saved

        Returns:
        None
        """
        self.training_data_file = training_data_file
        self.trained_model_file = trained_model_file

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
