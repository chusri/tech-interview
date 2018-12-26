// This class models the leaf node.

#ifndef LEAFNODE_H
#define LEAFNODE_H

class Node;
class Tree;

class LeafNode: public Node {
	public:
		friend class Tree;
		virtual void print(ostream&) = 0;
		virtual int eval(void) = 0;
};

#endif //LEAFNODE_H
