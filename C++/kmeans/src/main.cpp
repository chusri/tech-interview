/**
 * @file main.cpp
 * @brief This file implements the main thread of execution.
 * @author Nawab Ali
 */

#include "util.h"
#include "Point.h"
#include "Cluster.h"

int main(int argc, char** argv) {
	vector<double> v1{5.1,3.5,1.4,0.2};
	Point<double> point1(4);
	Point<double> point2(v1);
	Point<double> point3 = point2;
	vector<Point<double>> points{point1,point2,point3};
	Cluster<double> cluster1(1, points);

	cout << point3 << endl;
	cout << cluster1;

	return(0);
}
