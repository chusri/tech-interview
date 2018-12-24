// This class models a binary node in the expression tree.

#ifndef BINARYNODE_H
#define BINARYNODE_H

#include "Node.h"
#include "Tree.h"
#include<iostream>
#include<stdexcept>

using namespace std;

class BinaryNode: public Node {
	protected:
		char op;
		Tree left;
		Tree right;

	public:
		BinaryNode(char o, Tree l, Tree r): op(o), left(l), right(r) {}
		virtual void print(ostream& out);
		virtual int eval(void);
		friend class Tree;
};

virtual void BinaryNode::print(ostream& out) {
	out << "(" << left << op << right << ")";
}

virtual int BinaryNode::eval(void) {
	switch(op) {
		case '+':
			return(left.eval() + right.eval());
		case '-':
			return(left.eval() - right.eval());
		case '*':
			return(left.eval() * right.eval());
		case '/':
			return(left.eval() / right.eval());
		case '%':
			return(left.eval() % right.eval());
		default:
			throw invalid_argument("Invalid operator.");
	}
}

#endif //BINARYNODE_H
