import Node

class BinaryTree:
    """ This class implements a Binary Tree """

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
        assert(index >= 0 and index < len(vertexList))

        key, leftChildIndex, rightChildIndex = vertexList[index]
        node.addKey(key)

        if leftChildIndex == -1 and rightChildIndex == -1:
            return node
        else:
            self.addNode(node, self._createFromFile(Node.Node(), leftChildIndex, vertexList),
                         self._createFromFile(Node.Node(), rightChildIndex, vertexList))
            return node

    def clearTraversalResult(self):
        self.traversalResult = []


    def inorderTraversal(self, root):
        if root:
            self.inorderTraversal(root.getLeftChild())
            self.traversalResult.append(root.getKey())
            self.inorderTraversal(root.getRightChild())

        return self.traversalResult
