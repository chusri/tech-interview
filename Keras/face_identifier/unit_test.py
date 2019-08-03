#!/home/ubuntu/anaconda3/envs/tensorflow_p36/bin/python

import warnings
import unittest
from FaceIdentifier import *

class TestFaceIdentifier(unittest.TestCase):
    @unittest.skip('load_facenet_model() takes too long')
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

    def test_detect_face(self):
        image = 'data/5-celebrity-faces-dataset/val/ben_affleck/httpcsvkmeuaafdfjpg.jpg'
        face_identifier = FaceIdentifier('data/facenet_keras.h5')
        pixels = face_identifier._preprocess_image(image)
        x1, y1, x2, y2 = face_identifier._detect_face(pixels)
        self.assertEqual([x1, y1, x2, y2], [113, 42, 151, 94])

    def test_extract_face(self):
        image = 'data/5-celebrity-faces-dataset/val/ben_affleck/httpcsvkmeuaafdfjpg.jpg'
        face_identifier = FaceIdentifier('data/facenet_keras.h5')
        face = face_identifier._extract_face(image)
        self.assertEqual(face.shape, (160, 160, 3))

    def test_load_faces_from_dir(self):
        directory = 'data/5-celebrity-faces-dataset/val/ben_affleck/'
        face_identifier = FaceIdentifier('data/facenet_keras.h5')
        faces = face_identifier._load_faces_from_dir(directory)
        self.assertEqual(len(faces), 5)

if __name__ == '__main__':
    unittest.main()
