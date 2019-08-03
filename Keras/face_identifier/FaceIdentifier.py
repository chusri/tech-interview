#!/home/ubuntu/anaconda3/envs/tensorflow_p36/bin/python

""" Deep Learning system for identifying faces. """

import numpy as np
from PIL import Image
from mtcnn.mtcnn import MTCNN
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

    def extract_face(self, image):
        """
        Extract face from image.

        Arguments:
        self
        image -- image to be processed

        Returns:
        Resized face NumPy array
        """

        pixels = self._preprocess_image(image)
        x1, y1, x2, y2 = self._detect_face(pixels)
        return self._extract_face(pixels, x1, y1, x2, y2)

    def _load_facenet_model(self):
        """
        Load FaceNet model.

        Arguments:
        self

        Returns:
        Pre-trained FaceNet model
        """

        return load_model(self.facenet_model)

    def _preprocess_image(self, filename):
        """
        1. Convert to RGB
        2. Convert image to NumPy array

        Arguments:
        self
        filename -- image to be processed

        Returns:
        NumPy array representation of image
        """

        image = Image.open(filename).convert('RGB')
        return np.asarray(image)

    def _detect_face(self, pixels):
        """
        Detect face in image.

        Arguments:
        self
        pixels -- NumPy array representation of image

        Returns:
        Co-ordinates of face
        """

        mtcnn = MTCNN()
        faces = mtcnn.detect_faces(pixels)
        x1, y1, width, height = faces[0]['box']
        x1, y1 = abs(x1), abs(y1)
        x2, y2 = x1+width, y1+height

        return x1, y1, x2, y2

    def _extract_face(self, pixels, x1, y1, x2, y2):
        """
        Extract face in image.

        Arguments:
        self
        pixels -- NumPy array representation of image
        x1, y1, x2, y2 -- Co-ordinates of face

        Returns:
        Resized face array
        """

        face = pixels[y1:y2, x1:x2]
        image = Image.fromarray(face).resize((160, 160))
        return np.asarray(image)

