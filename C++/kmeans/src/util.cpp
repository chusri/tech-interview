/**
 * @file util.cpp
 * @brief This file implements common utility functions.
 * @author Nawab Ali
 */

#if 0
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
#endif
