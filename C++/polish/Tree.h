// This class models the expression Tree class.

#ifndef TREE_H
#define TREE_H

#include "Node.h"
#include "IntNode.h"
#include "VarNode.h"
#include "UnaryNode.h"
#include "BinaryNode.h"

class Tree {
	protected:
		Node *p;

	public:
		Tree(int);
		Tree(char, map<char, int>);
		Tree(char, Tree);
		Tree(char, Tree, Tree);
		Tree(const Tree&);
		void operator=(const Tree&);
		int eval(void);
		~Tree(void);
		friend class Node;
		friend ostream& operator<<(ostream&, const Tree&);
};

// Integer leaf node
Tree(int n) {
	p = new IntNode(n);
}

// Variable leaf node
Tree(char id, map<char, int> m) {
	p = new VarNode(id, m);
}

// Unary node
Tree(char op, Tree opnd) {
	p = new UnaryNode(op, opnd);
}

// Binary tree
Tree(char op, Tree left, Tree right) {
	p = new BinaryNode(op, left, right);
}

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

// Overload the = operator
void Tree::operator=(const Tree& t) {
	p = t.p;
	++p->gc;
}

#endif //TREE_H
