/**
 * @file util.h
 * @brief This file declares common utility functions.
 * @author Nawab Ali
 */

#ifndef UTIL_H
#define UTIL_H

#include<string>
#include<vector>

using namespace std;

/**
 * @brief This function reads training data from a file.
 * @param training_data_file Training data file.
 * @param num_features Number of features in the data.
 * @return 2-dimensional vector with the training data.
 */
template <class T>
vector<vector<T> >
read_training_data(string training_data_file, int num_features);

#endif //UTIL_H
