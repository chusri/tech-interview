/**
 * @file main.cpp
 * @brief This file implements the main thread of execution.
 * @author Nawab Ali
 */

#include<vector>
#include<string>
#include "util.h"
#include "Point.h"
#include "KMeans.h"
#include "Cluster.h"

int main(int argc, char** argv) {
	vector<Point<double>> points;
	vector<vector<double>> training_data = read_training_data<double>(string("../data/iris.txt"), 4);

	for_each(training_data.begin(), training_data.end(), [&points](vector<double> coordinates) {
		points.push_back(Point<double>(coordinates));
	});

	vector<Cluster<double>> clusters = KMeans<double>(3, points, 100);

	for_each(clusters.begin(), clusters.end(), [](Cluster<double> cluster) {
		cout << cluster << endl;
	});

	return(0);
}
