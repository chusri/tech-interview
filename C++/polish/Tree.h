// This class models the expression Tree class.

#ifndef TREE_H
#define TREE_H

#include "Node.h"

class Tree {
	protected:
		Node *p;

	public:
		Tree(int);
		Tree(char);
		Tree(char*, Tree);
		Tree(char*, Tree, Tree);
		Tree(const Tree&);
		void operator=(const Tree&);
		int eval(void);
		~Tree(void);
		friend class Node;
		friend ostream& operator<<(ostream&, const Tree&);
};

#endif //TREE_H
