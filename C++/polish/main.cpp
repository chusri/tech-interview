// main.cpp

#include<map>
#include<pair>
#include "Node.h"
#include "Tree.h"
#include "LeafNode.h"
#include "IntNode.h"
#include "VarNode.h"
#include "UnaryNode.h"
#include "BinaryNode.h"

using namepace std;

int main(int argc, char** argv) {
	map<char, int> m;
	m.insert(pair<char, int>('A', 3));
	m.insert(pair<char, int>('B', 4));

	Tree t1 = Tree('*', Tree('-', 5), Tree('+', 'A', 4));
	Tree t2 = Tree('+', Tree('-', 'A', 1), Tree('+', t1, 'B'));

	cout << t1 << t2 << endl;
	cout << t1.eval() << ", " << t2.eval() << endl;

	return(0);
}
