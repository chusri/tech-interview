import sys
import Node
import threading
import BinaryTree

sys.setrecursionlimit(10**6) # max depth of recursion
threading.stack_size(2**27)  # new thread will get stack of such size

def main():
    tree = BinaryTree.BinaryTree()
    root = tree.getRoot()

    root.addKey(1)
    leftChild = Node.Node(2)
    rightChild = Node.Node(3)

    tree.addNode(root, leftChild, rightChild)

    print(' '.join(str(x) for x in tree.inorderTraversal(root)))

    tree.clearTraversalResult()
    sys.exit()

threading.Thread(target=main).start()
