/**
 * @file kmeans.cpp
 * @brief This file implements the main thread of execution.
 * @author Nawab Ali
 */

#include "util.h"
#include<fstream>
#include<iostream>

template <class T>
vector<vector<T> >
read_training_data(string training_data_file, int num_features) {
	string line;
	ifstream file;
	vector<vector<T> > training_data;

	file.open(training_data_file);
	while (getline(file, line)) {
		cout << line << endl;
	}
	file.close();

	return(training_data);
}

int main(int argc, char** argv) {
	read_training_data<int>("../data/iris.txt", 4);
	return(0);
}
