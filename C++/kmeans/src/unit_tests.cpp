/**
 * @file unit_tests.cpp
 * @brief This file implements the unit tests.
 * @author Nawab Ali
 */

#include "util.h"
#include<gtest/gtest.h>

TEST (KMeansTest, TokenizeData) {
	vector<double> row0, row149;
	vector<double> row0_1, row0_2, row0_3;
	vector<double> row0_1_ground_truth{5.1,3.5,1.4};
	vector<double> row0_ground_truth{5.1,3.5,1.4,0.2};
	vector<double> row149_ground_truth{5.9,3.0,5.1,1.8};

	row0 = tokenize<double>("5.1,3.5,1.4,0.2,Iris-setosa", ',', 4);
	row0_1 = tokenize<double>("5.1,3.5,1.4,0.2,Iris-setosa", ',', 3);
	row0_2 = tokenize<double>("5.1,3.5,1.4,0.2,Iris-setosa", ',', 0);
	row0_3 = tokenize<double>("5.1,3.5,1.4,0.2,Iris-setosa", ',', -1);
	row149 = tokenize<double>("5.9,3.0,5.1,1.8,Iris-virginica", ',', 4);

	ASSERT_EQ(row0, row0_ground_truth);
	ASSERT_NE(row0, row149_ground_truth);
	ASSERT_EQ(row0_1, row0_1_ground_truth);
	ASSERT_EQ(row0_2.size(), 0);
	ASSERT_EQ(row0_3.size(), 0);
	ASSERT_EQ(row149, row149_ground_truth);
}

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
	ASSERT_NE(row0, row149_ground_truth);
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return(RUN_ALL_TESTS());
}
