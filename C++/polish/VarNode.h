// This class models the variable leaf node.

#ifndef VARNODE_H
#define VARNODE_H

class LeafNode;

class VarNode: public LeafNode {
	protected:
		char name;
		map<char, int> values;

	public:
		VarNode(char id, map<char, int> m): name(id), values(m) {}
		virtual void print(ostream& out) { out << name; }
		virtual int eval(void) { return(values[name]); }
		friend class Tree;
};

#endif //VARNODE_H
