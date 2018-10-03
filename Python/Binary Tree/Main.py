import Node
import BinaryTree

def main():
    tree = BinaryTree.BinaryTree()
    root = tree.getRoot()

    root.addKey(1)
    leftChild = Node.Node(2)
    rightChild = Node.Node(3)

    tree.addNode(root, leftChild, rightChild)
    tree.inorderTraversal(root)

if __name__ == '__main__':
    main()
