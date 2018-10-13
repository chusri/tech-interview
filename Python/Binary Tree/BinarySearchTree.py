import Node
from BinaryTree import BinaryTree

class BinarySearchTree(BinaryTree):
    """ This class implements a Binary Search Tree """

    def __init__(self):
        BinaryTree.__init__(self)
        self.height = 1

    def addNode(self, root, key):
        if root is None:
            return Node.Node(key)
        elif key < root.getKey():
            root.addLeftChild(self.addNode(root.getLeftChild(), key))
        else:
            root.addRightChild(self.addNode(root.getRightChild(), key))

        return root
