import sys
import Node
import threading
import BinaryTree

sys.setrecursionlimit(10**6) # max depth of recursion
threading.stack_size(2**27)  # new thread will get stack of such size

def main():
    inputFile = 'Test1.txt'
    outputFile = 'Test1_output.txt'

    tree = BinaryTree.BinaryTree(inputFile)

    with open(outputFile, 'w') as f:
        f.write(' '.join(str(x) for x in tree.inOrderTraversal(tree.getRoot())))
        f.write('\n')
        tree.clearTraversalResult()

        f.write(' '.join(str(x) for x in tree.preOrderTraversal(tree.getRoot())))
        f.write('\n')
        tree.clearTraversalResult()

        f.write(' '.join(str(x) for x in tree.postOrderTraversal(tree.getRoot())))
        f.write('\n')
        tree.clearTraversalResult()

    sys.exit()

threading.Thread(target=main).start()
