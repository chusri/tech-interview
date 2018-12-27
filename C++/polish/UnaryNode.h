// This class models a unary node in the expression tree.

#ifndef UNARYNODE_H
#define UNARYNODE_H

#include "Node.h"
#include "Tree.h"

class UnaryNode: public Node {
	protected:
		char op;
		Tree opnd;

	public:
		UnaryNode(char c, Tree t): op(c), opnd(t) {}
		virtual void print(ostream& out) { out << "(" << op << opnd << ")"; }
		virtual int eval(void);
		friend class Tree;
};

int UnaryNode::eval(void) {
	switch(op) {
		case '-':
			return(-1*opnd.eval());
			break;
		case '+':
			return(opnd.eval());
			break;
		default:
			throw invalid_argument("Invalid operator.");
			break;
	}
}

#endif //UNARYNODE_H
