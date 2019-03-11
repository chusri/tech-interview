/**
 * @file unit_tests.cpp
 * @brief This file implements the unit tests.
 * @author Nawab Ali
 */

#include "util.h"
#include "Point.h"
#include "Cluster.h"
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

TEST (KMeansTest, GetColumnFrom2Dvec) {
	vector<double> v1{2.1,3.2,1.4,0.2};
	vector<double> v2{3.1,4.2,1.4,1.2};
	vector<double> v3{4.1,5.2,1.4,1.2};
	vector<double> v4{5.1,6.2,1.4,1.2};
	vector<double> v1_t{2.1,3.1,4.1,5.1};
	vector<double> v2_t{3.2,4.2,5.2,6.2};
	vector<double> v3_t{1.4,1.4,1.4,1.4};
	vector<vector<double> > vec2d{v1,v2,v3,v4};

	ASSERT_EQ(v1_t, get_column_vector<double>(vec2d, 0));
	ASSERT_EQ(v2_t, get_column_vector<double>(vec2d, 1));
	ASSERT_EQ(v3_t, get_column_vector<double>(vec2d, 2));
	ASSERT_NE(v3_t, get_column_vector<double>(vec2d, 3));
}

// Unit tests for Point class
TEST (KMeansTest, PointClass) {
	vector<double> v1{5.1,3.5,1.4,0.2};
	vector<double> v2{3.1,6.5,1.4,1.2};
	Point<double> point1(4);
	Point<double> point2(v1);
	Point<double> point3 = point2;

	// Tests for constructors and getter functions
	ASSERT_EQ(4, point1.get_dimensions());
	ASSERT_EQ(v1, point2.get_coordinates());
	ASSERT_EQ(point3.get_dimensions(), point2.get_dimensions());
	ASSERT_EQ(point3.get_coordinates(), point2.get_coordinates());

	// Tests for setter function
	point2.set_coordinates(v2);
	ASSERT_EQ(v2, point2.get_coordinates());

	// Tests for overloaded = and == operators
	point1 = point3;
	ASSERT_EQ(point1, point3);
	ASSERT_EQ(point1.get_dimensions(), point3.get_dimensions());
	ASSERT_EQ(point1.get_coordinates(), point3.get_coordinates());
}

// Unit tests for Cluster class
TEST (KMeansTest, ClusterClass) {
	vector<double> v1{5.1,3.5,1.4,0.2};
	vector<double> v2{3.1,6.5,1.4,1.2};
	Point<double> point1(4);
	Point<double> point2(v1);
	Point<double> point3 = point2;

	vector<Point<double>> points{point1,point2,point3};
	Cluster<double> cluster1;
	Cluster<double> cluster2(2);
	Cluster<double> cluster3(3, points);
	Cluster<double> cluster4 = cluster3;

	// Tests for constructors and getter functions
	ASSERT_EQ(-1, cluster1.get_id());
	ASSERT_EQ(0, cluster1.get_num_points());
	ASSERT_EQ(2, cluster2.get_id());
	ASSERT_EQ(0, cluster2.get_num_points());
	ASSERT_EQ(3, cluster3.get_id());
	ASSERT_EQ(points, cluster3.get_points());
	ASSERT_EQ(cluster3, cluster4);

	// Tests for overloaded = and == operator
	cluster1 = cluster3;
	ASSERT_EQ(cluster1, cluster3);

	// Tests for setter functions
	cluster1.set_id(1);
	cluster1.set_points(points);
	cluster1.set_centroid(point2);
	ASSERT_EQ(1, cluster1.get_id());
	ASSERT_EQ(points, cluster1.get_points());
	ASSERT_EQ(point2, cluster1.get_centroid());

	// Tests for add_point and remove_point methods
	cluster2.add_point(point1);
	cluster2.add_point(point2);
	cluster2.add_point(point3);
	ASSERT_EQ(points, cluster2.get_points());

	cluster2.remove_point(point1);
	cluster2.remove_point(point2);
	cluster2.remove_point(point3);
	ASSERT_EQ(0, cluster2.get_num_points());

	// Remove point from an empty cluster
	cluster2.remove_point(point1);
	ASSERT_EQ(0, cluster2.get_num_points());
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return(RUN_ALL_TESTS());
}
