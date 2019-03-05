/**
 * @file main.cpp
 * @brief This file implements the main thread of execution.
 * @author Nawab Ali
 */

#include "util.h"
#include "Point.h"

int main(int argc, char** argv) {
	vector<double> v1{5.1,3.5,1.4,0.2};
	Point<double> point1(v1);

	cout << point1 << endl;
	return(0);
}
