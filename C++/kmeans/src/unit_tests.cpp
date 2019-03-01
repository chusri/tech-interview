/**
 * @file unit_tests.cpp
 * @brief This file implements the unit tests.
 * @author Nawab Ali
 */

#include "util.h"
#include<gtest/gtest.h>

TEST (KMeansTest, ReadTrainingData) {
	vector<double> row0, row149;
	vector<vector<double> > training_data;
	vector<double> row0_ground_truth{5.1,3.5,1.4,0.2};
	vector<double> row149_ground_truth{5.9,3.0,5.1,1.8};

  training_data = read_training_data<double>("../data/iris.txt", 4);
	row0 = training_data[0];
	row149 = training_data[149];

	ASSERT_EQ(150, training_data.size());
	ASSERT_EQ(row0, row0_ground_truth);
	ASSERT_EQ(row149, row149_ground_truth);
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return(RUN_ALL_TESTS());
}
