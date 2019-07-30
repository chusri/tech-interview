#!/home/ubuntu/anaconda3/envs/tensorflow_p36/bin/python

import unittest
from FaceIdentifier import *

class TestFaceIdentifier(unittest.TestCase):
    def test_load_facenet_model(self):
        face_identifier = FaceIdentifier('data/facenet_keras.h5')
        model = face_identifier._load_facenet_model()
        print(model.inputs)
        print(model.outputs)

if __name__ == '__main__':
   unittest.main()
