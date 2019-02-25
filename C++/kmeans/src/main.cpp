/**
 * @file main.cpp
 * @brief This file implements the main thread of execution.
 * @author Nawab Ali
 */

#include "util.h"
#include<algorithm>

void print_vector(vector<double> v) {
	for_each(v.begin(), v.end(), [](double d) {
			cout << d << " ";
	});
	cout << endl;
}

int main(int argc, char** argv) {
	vector<vector<double> > training_data;

	training_data = read_training_data<double>("../data/iris.txt", 4);

	// Print the training data
	for_each(training_data.begin(), training_data.end(), print_vector);
	return(0);
}
