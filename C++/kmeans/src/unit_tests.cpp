/**
 * @file unit_tests.cpp
 * @brief This file implements the unit tests.
 * @author Nawab Ali
 */

#include "util.h"
#include<gtest/gtest.h>

TEST (KMeansTest, VectorSize) {
	vector<vector<double> > training_data;
  training_data = read_training_data<double>("../data/iris.txt", 4);

	ASSERT_EQ(150, training_data.size());
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return(RUN_ALL_TESTS());
}
