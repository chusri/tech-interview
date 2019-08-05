#!/home/ubuntu/anaconda3/envs/tensorflow_p36/bin/python

""" Deep Learning system for identifying faces. """

import os
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

    def _load_facenet_model(self):
        """
        Load FaceNet model.

        Arguments:
        self

        Returns:
        Pre-trained FaceNet model
        """

        return load_model(self.facenet_model)

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

    def _load_dataset(self, directory):
        """
        Extract and return faces from images in directory.

        Arguments:
        self
        directory -- directory with images

        Returns:
        List of extracted faces with labels
        """

        X, y = list(), list()
        for subdir in os.listdir(directory):
            path = directory+'/'+subdir+'/'
            if not os.path.isdir(path):
                continue
            faces = self._load_faces_from_dir(path)
            labels = [subdir for _ in range(len(faces))]
            print('>loaded %d images from class %s' % (len(faces), subdir))
            X.extend(faces)
            y.extend(labels)
        return np.asarray(X), np.asarray(y)

    def _load_faces_from_dir(self, directory):
        """
        Extract and return faces from images in directory.

        Arguments:
        self
        directory -- directory with images

        Returns:
        List of extracted faces
        """

        faces = list()
        for filename in os.listdir(directory):
            faces.append(self._extract_face(directory+filename))
        return faces

    def _extract_face(self, image):
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
        return self._extract_face_array(pixels, x1, y1, x2, y2)

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

    def _extract_face_array(self, pixels, x1, y1, x2, y2):
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
