class Node:
    """ This class implements a node in a Binary Tree. """

    def __init__(self, key=None, leftChild=None, rightChild=None):
        self.key = key
        self.leftChild = leftChild
        self.rightChild = rightChild

    def addKey(self, key):
        self.key = key

    def addLeftChild(self, leftChild):
        self.leftChild = leftChild

    def addRightChild(self, rightChild):
        self.rightChild = rightChild

    def getKey(self):
        return self.key

    def getLeftChild(self):
        return self.leftChild

    def getRightChild(self):
        return self.rightChild
