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

// Copy constructor
Tree::Tree(const Tree& t) {
	p = t.p;
	++p->gc;
}

// Evaluate the expression
int Tree::eval(void) {
	return(p->eval());
}

// Destructor
Tree::~Tree(void) {
	if (--p->gc == 0) {
		delete p;
	}
}

// Overload the << operator
ostream& operator<<(ostream& out, const Tree& t) {
	t.p->print(out);
	return(out);
}

#endif //TREE_H
