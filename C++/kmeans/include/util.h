/**
 * @file util.h
 * @brief This file implements common utility functions.
 * @author Nawab Ali
 */

#ifndef UTIL_H
#define UTIL_H

#include<string>
#include<vector>
#include<fstream>
#include<iostream>

using namespace std;

/**
 * @brief This function reads training data from a file.
 * @param training_data_file Training data file.
 * @param num_features Number of features in the data.
 * @return 2-dimensional vector with the training data.
 */
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

#endif //UTIL_H
