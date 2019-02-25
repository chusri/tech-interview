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
#include<sstream>
#include<iostream>
#include<boost/lexical_cast.hpp>
#include<boost/algorithm/string.hpp>

using namespace std;

/**
 * @brief This function splits a string into tokens.
 * @param delimiter Delimiter character.
 * @param num_features Number of features in the data.
 * @return Vector containing tokenized string.
 */
template <class T>
vector<T> tokenize(const string& str, char delimiter, int num_features) {
	string token;
	vector<T> tokens;
	int token_count = 0;
	istringstream token_stream(str);

	// Convert str to tokens. Only process the first num_features tokens.
	while (getline(token_stream, token, delimiter) && token_count < num_features) {
		boost::trim(token);
		tokens.push_back(boost::lexical_cast<T>(token));
		token_count++;
	}

	return(tokens);
}

/**
 * @brief This function reads training data from a csv file.
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
		training_data.push_back(tokenize<T>(line, ',', num_features));
	}

	file.close();
	return(training_data);
}

#endif //UTIL_H
