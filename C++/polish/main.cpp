// main.cpp

#include<map>
#include<iostream>
#include<stdexcept>

#include "Tree.h"

using namespace std;

int main(int argc, char** argv) {
	map<char, int> m;
	m.insert(pair<char, int>('A', 3));
	m.insert(pair<char, int>('B', 4));

	Tree ta = Tree('A', m);
	Tree tb = Tree('B', m);

	Tree t1 = Tree('*', Tree('-', 5), Tree('+', ta, 4));
	Tree t2 = Tree('+', Tree('-', ta, 1), Tree('+', t1, tb));

	cout << ta << tb << endl;
	cout << t1 << t2 << endl;
	cout << t1.eval() << ", " << t2.eval() << endl;

	return(0);
}
