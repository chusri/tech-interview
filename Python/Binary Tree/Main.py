import sys
import Node
import threading
import BinaryTree
import BinarySearchTree

sys.setrecursionlimit(10**6) # max depth of recursion
threading.stack_size(2**27)  # new thread will get stack of such size

def main():
    inputFile = 'Test0.txt'
    outputFile = 'Test0_output.txt'

    tree = BinaryTree.BinaryTree(inputFile)
    bst = BinarySearchTree.BinarySearchTree()

    # Binary Tree tests
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

    print(tree.isBST(tree.getRoot()))

    # Binary Search Tree tests
    print(bst.isBST(bst.getRoot()))

    sys.exit()

threading.Thread(target=main).start()
