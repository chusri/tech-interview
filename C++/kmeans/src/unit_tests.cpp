/**
 * @file unit_tests.cpp
 * @brief This file implements the unit tests.
 * @author Nawab Ali
 */

#include "util.h"
#include "Point.h"
#include<gtest/gtest.h>

// Unit tests for utility functions
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

// Unit tests for Point class
TEST (KMeansTest, PointClass) {
	vector<double> v1{5.1,3.5,1.4,0.2};
	vector<double> v2{3.1,6.5,1.4,1.2};
	Point<double> point1(4);
	Point<double> point2(4, v1);
	Point<double> point3 = point2;

	// Tests for constructors and getter functions
	ASSERT_EQ(4, point1.get_dimensions());
	ASSERT_EQ(v1, point2.get_coordinates());
	ASSERT_EQ(point3.get_dimensions(), point2.get_dimensions());
	ASSERT_EQ(point3.get_coordinates(), point2.get_coordinates());

	// Tests for setter function
	point2.set_coordinates(v2);
	ASSERT_EQ(v2, point2.get_coordinates());

	// Tests for overloaded assignment operator
	point1 = point3;
	ASSERT_EQ(point1.get_dimensions(), point3.get_dimensions());
	ASSERT_EQ(point1.get_coordinates(), point3.get_coordinates());
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return(RUN_ALL_TESTS());
}
