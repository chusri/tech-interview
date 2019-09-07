import Node

class BinaryTree:
    """ This class implements a Binary Tree """

    # Class variable used in isBST() method
    _prevNode = None

    def __init__(self, filename=None):
        self.root = Node.Node()
        self.traversalResult = []

        if filename is not None:
            vertexList = self._readFromFile(filename)
            self._createFromFile(self.root, 0, vertexList)


    def getRoot(self):
        return self.root


    def addNode(self, node, leftChild=None, rightChild=None):
        assert(node and node.getKey() is not None)

        if node.getLeftChild() is None:
            node.addLeftChild(leftChild)

        if node.getRightChild() is None:
            node.addRightChild(rightChild)


    def _readFromFile(self, filename):
        numLines = 0
        numVertices = 0
        vertexList = []

        with open(filename, 'r') as f:
            for line in f:
                if numLines == 0:
                    numVertices = long(line.strip())
                else:
                    vertexList.append(map(int, line.split()))
                numLines += 1

        assert((numLines-1) == numVertices)
        return vertexList


    def _createFromFile(self, node, index, vertexList):
        if len(vertexList) == 0:
            node = None
            return node

        assert(index >= 0 and index < len(vertexList))

        key, leftChildIndex, rightChildIndex = vertexList[index]
        node.addKey(key)

        if leftChildIndex == -1 and rightChildIndex == -1:
            pass
        elif leftChildIndex == -1:
            self.addNode(node, None,
                         self._createFromFile(Node.Node(), rightChildIndex, vertexList))
        elif rightChildIndex == -1:
            self.addNode(node, self._createFromFile(Node.Node(), leftChildIndex, vertexList),
                         None)
        else:
            self.addNode(node, self._createFromFile(Node.Node(), leftChildIndex, vertexList),
                         self._createFromFile(Node.Node(), rightChildIndex, vertexList))
        return node


    def clearTraversalResult(self):
        self.traversalResult = []


    def inOrderTraversal(self, root):
        if root:
            self.inOrderTraversal(root.getLeftChild())
            self.traversalResult.append(root.getKey())
            self.inOrderTraversal(root.getRightChild())

        return self.traversalResult


    def preOrderTraversal(self, root):
        if root:
            self.traversalResult.append(root.getKey())
            self.preOrderTraversal(root.getLeftChild())
            self.preOrderTraversal(root.getRightChild())

        return self.traversalResult


    def postOrderTraversal(self, root):
        if root:
            self.postOrderTraversal(root.getLeftChild())
            self.postOrderTraversal(root.getRightChild())
            self.traversalResult.append(root.getKey())

        return self.traversalResult


    def isBST(self, root):
        """ Is the binary tree a binary search tree? """

        if root is None:
            # Empty binary tree is a BST
            return True

        if self.isBST(root.getLeftChild()) is False:
            return False

        if BinaryTree._prevNode is not None and BinaryTree._prevNode.getKey() > root.getKey():
            return False

        BinaryTree._prevNode = root
        return self.isBST(root.getRightChild())
