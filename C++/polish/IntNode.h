// This class models an integer leaf node.

#ifndef INTNODE_H
#define INTNODE_H

#include<iostream>
#include "LeafNode.h"

using namespace std;

class IntNode: public LeafNode {
	protected:
		int n;

	public:
		IntNode(int k): n(k) {}
		virtual void print(ostream& out) { out << n; }
		virtual int eval(void) { return(n); }
		friend class Tree;
};

#endif //INTNODE_H
