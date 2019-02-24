/**
 * @file kmeans.cpp
 * @brief This file implements the main thread of execution.
 * @author Nawab Ali
 */

#include "util.h"

int main(int argc, char** argv) {
	read_training_data<int>("../data/iris.txt", 4);
	return(0);
}
