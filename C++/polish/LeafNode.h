// This class models the leaf node.

#ifndef LEAFNODE_H
#define LEAFNODE_H

#include "Node.h"
#include "Tree.h"
#include<iostream>

using namespace std;

class LeafNode: public Node {
	public:
		friend class Tree;
		virtual void print(ostream&) = 0;
		virtual int eval(void) = 0;
};

#endif //LEAFNODE_H
