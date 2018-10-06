import sys
import Node
import threading
import BinaryTree

sys.setrecursionlimit(10**6) # max depth of recursion
threading.stack_size(2**27)  # new thread will get stack of such size

def main():
    tree = BinaryTree.BinaryTree('Test0.txt')

    print(' '.join(str(x) for x in tree.inOrderTraversal(tree.getRoot())))
    tree.clearTraversalResult()

    print(' '.join(str(x) for x in tree.preOrderTraversal(tree.getRoot())))
    tree.clearTraversalResult()

    print(' '.join(str(x) for x in tree.postOrderTraversal(tree.getRoot())))
    tree.clearTraversalResult()

    sys.exit()

threading.Thread(target=main).start()
