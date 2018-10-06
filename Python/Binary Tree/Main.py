import sys
import Node
import threading
import BinaryTree

sys.setrecursionlimit(10**6) # max depth of recursion
threading.stack_size(2**27)  # new thread will get stack of such size

def main():
    tree = BinaryTree.BinaryTree('Test1.txt')

    print(' '.join(str(x) for x in tree.inorderTraversal(tree.getRoot())))

    tree.clearTraversalResult()
    sys.exit()

threading.Thread(target=main).start()
