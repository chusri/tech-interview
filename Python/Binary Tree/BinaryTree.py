import Node

class BinaryTree:
    """ This class implements a Binary Tree """

    def __init__(self):
        self.root = Node.Node()

    def getRoot(self):
        return self.root

    def addNode(self, node, leftChild=None, rightChild=None):
        assert(node and node.getKey() is not None)

        if node.getLeftChild() is None:
            node.addLeftChild(leftChild)

        if node.getRightChild() is None:
            node.addRightChild(rightChild)

    def inorderTraversal(self, root):
        if root:
            self.inorderTraversal(root.getLeftChild())
            print(root.getKey())
            self.inorderTraversal(root.getRightChild())
