// This class models the Node abstract class. The classes derived from Node
// represent the nodes in the expression tree.

#ifndef NODE_H
#define NODE_H

#include "Tree.h"
#include<iostream>

using namespace std;

class Node {
	protected:
		int gc; // reference count

	public:
		Node(void) { gc = 1; }
		virtual void print(ostream&) = 0;
		virtual int eval(void) = 0;
		virtual ~Node(void) {};
		friend class Tree;
		friend ostream& operator <<(ostream&, const Tree&);
};

#endif //NODE_H
