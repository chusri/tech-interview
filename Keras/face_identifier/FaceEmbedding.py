""" Deep Learning system for creating face embeddings. """

import numpy as np
from keras.models import load_model

class FaceEmbedding(object):
    def __init__(self, facenet_model):
        """
        Initialize FaceEmbedding object.

        Arguments:
        self
        facenet_model -- pre-trained FaceNet model

        Returns:
        None
        """

        self.facenet_model = load_model(facenet_model)

    def get_face_embedding(self, pixels):
        """
        Return face embedding.

        Arguments:
        self
        pixels -- pixels of face

        Returns:
        Face embedding
        """

        samples = self._normalize_face_pixels(pixels)
        yhat = self.facenet_model.predict(samples)
        return yhat[0]

    def _normalize_face_pixels(self, pixels):
        """
        Normalize face for embedding.

        Arguments:
        self
        pixels -- pixels of face

        Returns:
        Normalized face pixels
        """

        pixels = pixels.astype('float32')
        mean, stddev = pixels.mean(), pixels.std()
        pixels = (pixels-mean)/stddev
        return np.expand_dims(pixels, axis=0)
