// This class models a binary node in the expression tree.

#ifndef BINARYNODE_H
#define BINARYNODE_H

class Node;
class Tree;

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

void BinaryNode::print(ostream& out) {
	out << "(" << left << op << right << ")";
}

int BinaryNode::eval(void) {
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
