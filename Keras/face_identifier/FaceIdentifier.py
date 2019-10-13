#!/home/ubuntu/anaconda3/envs/tensorflow_p36/bin/python

""" Deep Learning system for identifying faces. """

import warnings
from Image import *
from ImageData import *
from FaceEmbedding import *
from FaceIdentifier import *
from numpy import savez_compressed
from sklearn.preprocessing import Normalizer
from sklearn.preprocessing import LabelEncoder

class FaceIdentifier(object):
    def __init__(self):
        """
        Initialize FaceIdentifier object.

        Arguments:
        self

        Returns:
        None
        """

        pass

def main():
    warnings.filterwarnings('ignore')
    facenet_model = 'data/facenet_keras.h5'
    training_dir = 'data/5-celebrity-faces-dataset/train'
    validation_dir = 'data/5-celebrity-faces-dataset/val'
    face_embeddings_file = 'data/5-celebrity-faces-embeddings.npz'

    train_x, train_y, test_x, test_y = load_data(training_dir, validation_dir)
    embedding_train_x, embedding_test_x = get_face_embeddings(facenet_model, train_x, test_x)
    norm_embedding_train_x, norm_embedding_test_x = normalize_face_embeddings(embedding_train_x,
                                                                              embedding_test_x)
    encoded_train_y, encoded_test_y = encode_labels(train_y, test_y)

    savez_compressed(face_embeddings_file, norm_embedding_train_x, encoded_train_y,
                     norm_embedding_test_x, encoded_test_y)

def load_data(training_dir, validation_dir):
    """
    Load training and validation data.

    Arguments:
    training_dir -- directory with training data
    validation_dir -- directory with validation data

    Returns:
    train_x -- training data
    train_y -- training data label
    test_x -- validation data
    test_y -- validation data label
    """

    training_data = ImageData(training_dir)
    train_x, train_y = training_data.load_dataset()
    validation_data = ImageData(validation_dir)
    test_x, test_y = validation_data.load_dataset()

    return train_x, train_y, test_x, test_y

def get_face_embeddings(facenet_model, train_x, test_x):
    """
    Return face embeddings.

    Arguments:
    facenet_model -- trained FaceNet model
    train_x -- training data
    test_x -- validation data

    Returns:
    embedding_train_x -- embeddings of training data
    embedding_test_x -- embeddings of validation data
    """

    face_embedding = FaceEmbedding(facenet_model)

    embedding_train_x = [face_embedding.get_face_embedding(face) for face in train_x]
    embedding_test_x = [face_embedding.get_face_embedding(face) for face in test_x]

    return embedding_train_x, embedding_test_x

def normalize_face_embeddings(embedding_train_x, embedding_test_x):
    """
    Normalize face embeddings.

    Arguments:
    embedding_train_x -- embeddings of training data
    embedding_test_x -- embeddings of validation data

    Returns:
    Normalized face embedding vectors
    """

    normalizer = Normalizer(norm='l2')
    return normalizer.transform(embedding_train_x), normalizer.transform(embedding_test_x)

def encode_labels(train_y, test_y):
    """
    Encode string labels into integers.

    Arguments:
    train_y -- training data labels
    test_y -- validation data labels

    Returns:
    Encoded data labels
    """

    encoder = LabelEncoder()
    encoder.fit(train_y)

    return encoder.transform(train_y), encoder.transform(test_y)

if __name__ == '__main__':
    main()
