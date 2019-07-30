#!/home/ubuntu/anaconda3/envs/tensorflow_p36/bin/python

""" Deep Learning system for identifying faces. """

from keras.models import load_model

class FaceIdentifier(object):
    def __init__(self, facenet_model):
        """
        Initialize FaceIdentifier object.

        Arguments:
        self
        facenet_model -- pre-trained FaceNet model

        Returns:
        None
        """

        self.facenet_model = facenet_model

    def _load_facenet_model(self):
        """
        Load FaceNet model.

        Arguments:
        self

        Returns:
        Pre-trained FaceNet model
        """

        return load_model(self.facenet_model)

