#!/home/ubuntu/anaconda3/envs/tensorflow_p36/bin/python

import warnings
import unittest
from FaceIdentifier import *

class TestFaceIdentifier(unittest.TestCase):
    def test_load_facenet_model(self):
        warnings.filterwarnings('ignore')
        face_identifier = FaceIdentifier('data/facenet_keras.h5')
        model = face_identifier._load_facenet_model()
        print(model.inputs)
        print(model.outputs)

    def test_preprocess_image(self):
        image = 'data/5-celebrity-faces-dataset/val/ben_affleck/httpcsvkmeuaafdfjpg.jpg'
        face_identifier = FaceIdentifier('data/facenet_keras.h5')
        pixels = face_identifier._preprocess_image(image)
        self.assertEqual(pixels.shape, (264, 200, 3))

if __name__ == '__main__':
    unittest.main()
