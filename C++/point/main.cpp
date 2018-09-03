#include "point.h"

int main(int argc, char **argv) {
	point p1;
	point p2(3.61);
	point p3(2.53, 3.02);
	point p4 = p2 + p3;

	cout << p1 << endl;
	cout << p2 << endl;
	cout << p3 << endl;
	cout << p4 << endl;

	return 0;
}
