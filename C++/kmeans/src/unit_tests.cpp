/**
 * @file unit_tests.cpp
 * @brief This file implements the unit tests.
 * @author Nawab Ali
 */

#include "util.h"
#include "Point.h"
#include "KMeans.h"
#include "Cluster.h"
#include<gtest/gtest.h>

// Unit tests for tokenize utility function
TEST (KMeansTest, UtilTokenizeDataTokensSizeNotEqualNumFeatures) {
	EXPECT_THROW(tokenize<double>("5.1,3.5", ',', 4), length_error);
}

TEST (KMeansTest, UtilTokenizeDataDim4) {
	vector<double> tokens;
	vector<double> expected_tokens{5.1,3.5,1.4,0.2};

	tokens = tokenize<double>("5.1,3.5,1.4,0.2,Iris-setosa", ',', 4);

	ASSERT_EQ(tokens, expected_tokens);
}

TEST (KMeansTest, UtilTokenizeDataDim3) {
	vector<double> tokens;
	vector<double> expected_tokens{5.1,3.5,1.4};

	tokens = tokenize<double>("5.1,3.5,1.4,0.2,Iris-setosa", ',', 3);

	ASSERT_EQ(tokens, expected_tokens);
}

TEST (KMeansTest, UtilTokenizeDataDim0) {
	vector<double> tokens;

	tokens = tokenize<double>("5.1,3.5,1.4,0.2,Iris-setosa", ',', 0);

	ASSERT_EQ(tokens.size(), 0);
}

// Unit tests for read_training_data utility function
TEST (KMeansTest, UtilReadTrainingDataSize) {
	vector<vector<double> > training_data;

  training_data = read_training_data<double>("../data/iris.txt", 4);

	ASSERT_EQ(150, training_data.size());
}

TEST (KMeansTest, UtilReadTrainingDataFirstRow) {
	vector<double> row0{5.1,3.5,1.4,0.2};
	vector<vector<double> > training_data;

  training_data = read_training_data<double>("../data/iris.txt", 4);

	ASSERT_EQ(row0, training_data[0]);
}

TEST (KMeansTest, UtilReadTrainingDataLastRow) {
	vector<vector<double> > training_data;
	vector<double> row149{5.9,3.0,5.1,1.8};

  training_data = read_training_data<double>("../data/iris.txt", 4);

	ASSERT_EQ(row149, training_data[149]);
}

// Unit tests for get_column_vector utility function
TEST (KMeansTest, UtilGetColumnFrom2DVecIndexMoreThanEqualRowSize) {
	vector<double> v1{2.1,3.2,1.4,0.2};
	vector<double> v2{3.1,4.2,1.4,1.2};
	vector<double> v3{4.1,5.2,1.4,1.2};
	vector<double> v4{5.1,6.2,1.4,1.2};
	vector<vector<double> > vec2d{v1,v2,v3,v4};

	EXPECT_THROW(get_column_vector<double>(vec2d, 4), invalid_argument);
}

TEST (KMeansTest, UtilGetColumnFrom2DVecCol0) {
	vector<double> v1{2.1,3.2,1.4,0.2};
	vector<double> v2{3.1,4.2,1.4,1.2};
	vector<double> v3{4.1,5.2,1.4,1.2};
	vector<double> v4{5.1,6.2,1.4,1.2};
	vector<vector<double> > vec2d{v1,v2,v3,v4};
	vector<double> expected_col0{2.1,3.1,4.1,5.1};

	vector<double> col0 = get_column_vector<double>(vec2d, 0);

	ASSERT_EQ(col0, expected_col0);
}

TEST (KMeansTest, UtilGetColumnFrom2DVecCol1) {
	vector<double> v1{2.1,3.2,1.4,0.2};
	vector<double> v2{3.1,4.2,1.4,1.2};
	vector<double> v3{4.1,5.2,1.4,1.2};
	vector<double> v4{5.1,6.2,1.4,1.2};
	vector<vector<double> > vec2d{v1,v2,v3,v4};
	vector<double> expected_col1{3.2,4.2,5.2,6.2};

	vector<double> col1 = get_column_vector<double>(vec2d, 1);

	ASSERT_EQ(col1, expected_col1);
}

TEST (KMeansTest, UtilGetColumnFrom2DVecCol3) {
	vector<double> v1{2.1,3.2,1.4,0.2};
	vector<double> v2{3.1,4.2,1.4,1.2};
	vector<double> v3{4.1,5.2,1.4,1.2};
	vector<double> v4{5.1,6.2,1.4,1.2};
	vector<vector<double> > vec2d{v1,v2,v3,v4};
	vector<double> expected_col3{0.2,1.2,1.2,1.2};

	vector<double> col3 = get_column_vector<double>(vec2d, 3);

	ASSERT_EQ(col3, expected_col3);
}

// Unit tests for Point class
TEST (KMeansTest, PointConstructorDim) {
	Point<double> point(4);

	int dimensions = point.get_dimensions();
	vector<double> coordinates = point.get_coordinates();

	ASSERT_EQ(4, dimensions);
	ASSERT_EQ(4, coordinates.size());
}

TEST (KMeansTest, PointConstructorCoordinates) {
	vector<double> v{5.1,3.5,1.4,0.2};
	Point<double> point(v);

	int dimensions = point.get_dimensions();
	vector<double> coordinates = point.get_coordinates();

	ASSERT_EQ(4, dimensions);
	ASSERT_EQ(v, coordinates);
}

TEST (KMeansTest, PointSetCoordinates) {
	Point<double> point(4);
	vector<double> v{5.1,3.5,1.4,0.2};

	point.set_coordinates(v);
	vector<double> coordinates = point.get_coordinates();

	ASSERT_EQ(v, coordinates);
}

TEST (KMeansTest, PointOverloadAssignmentOperator) {
	vector<double> v{5.1,3.5,1.4,0.2};
	Point<double> point1(4);
	Point<double> point2(v);

	point1 = point2;

	ASSERT_EQ(point1, point2);
}

TEST (KMeansTest, PointOverloadEqualOperator) {
	vector<double> v{5.1,3.5,1.4,0.2};
	Point<double> point1(4);
	Point<double> point2(v);

	point1 = point2;
	bool b1 = (point1 == point2);
	bool b2 = (point1.get_dimensions() == point2.get_dimensions()) &&
						(point1.get_coordinates() == point2.get_coordinates());

	ASSERT_EQ(b1, b2);
}

// Unit tests for Cluster class
TEST (KMeansTest, ClusterConstructorNoArg) {
	Cluster<double> cluster;

	int id = cluster.get_id();
	long num_points = cluster.get_num_points();

	ASSERT_EQ(-1, id);
	ASSERT_EQ(0, num_points);
}

TEST (KMeansTest, ClusterConstructorId) {
	Cluster<double> cluster(1);

	int id = cluster.get_id();
	long num_points = cluster.get_num_points();

	ASSERT_EQ(1, id);
	ASSERT_EQ(0, num_points);
}

TEST (KMeansTest, ClusterConstructorPoints) {
	vector<double> v{5.1,3.5,1.4,0.2};
	Point<double> point1(4);
	Point<double> point2(v);
	Point<double> point3 = point2;
	vector<Point<double>> points{point1,point2,point3};
	Cluster<double> cluster(1, points);

	int id = cluster.get_id();
	vector<Point<double>> returned_points = cluster.get_points();

	ASSERT_EQ(1, id);
	ASSERT_EQ(points, returned_points);
}

TEST (KMeansTest, ClusterOverloadAssignmentOperator) {
	vector<double> v{5.1,3.5,1.4,0.2};
	Point<double> point1(4);
	Point<double> point2(v);
	Point<double> point3 = point2;
	vector<Point<double>> points{point1,point2,point3};
	Cluster<double> cluster1(1, points);
	Cluster<double> cluster2(2);

	cluster2 = cluster1;

	ASSERT_EQ(cluster1, cluster2);
}

TEST (KMeansTest, ClusterOverloadEqualOperator) {
	vector<double> v{5.1,3.5,1.4,0.2};
	Point<double> point1(4);
	Point<double> point2(v);
	Point<double> point3 = point2;
	vector<Point<double>> points{point1,point2,point3};
	Cluster<double> cluster1(1, points);
	Cluster<double> cluster2(2);

	cluster2 = cluster1;
	bool b1 = (cluster1 == cluster2);
	bool b2 = (cluster1.get_id() == cluster2.get_id() &&
						 cluster1.get_points() == cluster2.get_points());

	ASSERT_EQ(b1, b2);
}

TEST (KMeansTest, ClusterSetId) {
	Cluster<double> cluster;

	cluster.set_id(1);
	int id = cluster.get_id();

	ASSERT_EQ(1, id);
}

TEST (KMeansTest, ClusterSetPoint) {
	vector<double> v{5.1,3.5,1.4,0.2};
	Point<double> point1(4);
	Point<double> point2(v);
	Point<double> point3 = point2;
	vector<Point<double>> points{point1,point2,point3};
	Cluster<double> cluster(1);

	cluster.set_points(points);
	vector<Point<double>> returned_points = cluster.get_points();

	ASSERT_EQ(points, returned_points);
}

TEST (KMeansTest, ClusterSetCentroid) {
	vector<double> v{5.1,3.5,1.4,0.2};
	Point<double> point(v);
	Cluster<double> cluster(1);

	cluster.set_centroid(point);
	Point<double> returned_centroid = cluster.get_centroid();

	ASSERT_EQ(point, returned_centroid);
}

TEST (KMeansTest, ClusterAddPoint) {
	vector<double> v{5.1,3.5,1.4,0.2};
	Point<double> point(v);
	vector<Point<double>> points{point};
	Cluster<double> cluster(1);

	cluster.add_point(point);
	vector<Point<double>> returned_points = cluster.get_points();

	ASSERT_EQ(points, returned_points);
}

TEST (KMeansTest, ClusterRemovePoint) {
	vector<double> v{5.1,3.5,1.4,0.2};
	Point<double> point(v);
	Cluster<double> cluster(1);

	cluster.add_point(point);
	cluster.remove_point(point);
	int num_points = cluster.get_num_points();

	ASSERT_EQ(0, num_points);
}

TEST (KMeansTest, ClusterRemovePointFromEmptyCluster) {
	vector<double> v{5.1,3.5,1.4,0.2};
	Point<double> point(v);
	Cluster<double> cluster(1);

	cluster.remove_point(point);
	int num_points = cluster.get_num_points();

	ASSERT_EQ(0, num_points);
}

TEST (KMeansTest, ClusterCalculateCentroid) {
	vector<double> v1{5.1,3.5,1.4,0.2};
	vector<double> v2{3.1,6.5,1.4,1.2};
	vector<double> v3{2.1,8.5,3.4,9.2};
	vector<double> v4{3.43333,6.16667,2.06667,3.53333};

	Point<double> point1(v1);
	Point<double> point2(v2);
	Point<double> point3(v3);
	Point<double> point4(v4);

	vector<Point<double>> points{point1,point2,point3};
	Cluster<double> cluster(1, points);
	vector<double> centroid_coordinates = cluster.get_centroid().get_coordinates();

	for (int i = 0; i < point4.get_coordinates().size(); i++) {
		ASSERT_NEAR(point4.get_coordinates()[i],
								centroid_coordinates[i], 0.00001);
	}
}

// Unit tests for KMeans algorithm
TEST (KMeansTest, KMeansGetRandomPointsKMoreThanPoints) {
	vector<double> v{5.1,3.5,1.4,0.2};
	Point<double> point(v);
	vector<Point<double>> points{point};

	EXPECT_THROW(get_random_points<double>(2, points), invalid_argument);
}

TEST (KMeansTest, KMeansGetRandomPointsKEqualToPoints) {
	vector<double> v{5.1,3.5,1.4,0.2};
	Point<double> point(v);
	vector<Point<double>> points{point};

	vector<Point<double>> random_points = get_random_points<double>(1, points);

	ASSERT_EQ(random_points, points);
}

TEST (KMeansTest, KMeansInitClusterCentroidClustersSizeMoreThanPointsSize) {
	vector<double> v{5.1,3.5,1.4,0.2};
	Point<double> point(v);
	vector<Point<double>> points{point};
	Cluster<double> cluster1(1);
	Cluster<double> cluster2(2);
	vector<Cluster<double>> clusters{cluster1, cluster2};

	EXPECT_THROW(init_cluster_centroid<double>(clusters, points), invalid_argument);
}

TEST (KMeansTest, KMeansInitClusterCentroid) {
	vector<double> v{5.1,3.5,1.4,0.2};
	Point<double> point(v);
	vector<Point<double>> points{point};
	Cluster<double> cluster(1);
	vector<Cluster<double>> clusters{cluster};

	init_cluster_centroid<double>(clusters, points);
	Point<double> centroid = clusters[0].get_centroid();

	ASSERT_EQ(point, centroid);
}

TEST (KMeansTest, KMeansKMoreThanPointsSize) {
	vector<double> v{5.1,3.5,1.4,0.2};
	Point<double> point(v);
	vector<Point<double>> points{point};

	EXPECT_THROW(KMeans<double>(2, points), invalid_argument);
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return(RUN_ALL_TESTS());
}
