/**
 * @file KMeans.h
 * @brief This file implements the KMeans clustering algorithm.
 * @author Nawab Ali
 */

#ifndef KMEANS_H
#define KMEANS_H

#include "Point.h"
#include "Cluster.h"
#include<random>
#include<vector>
#include<functional>

/**
 * @brief This function returns k random points from the dataset.
 * @param k Number of clusters
 * @param points Vector of points
 * @return Vector of k random points
 */
template <class T>
vector<Point<double>> get_random_points(unsigned int k, const vector<Point<T>>& points) {
	random_device device;
	mt19937 generator(device());
	uniform_int_distribution<int> distribution(0, points.size()-1);
	vector<Point<double>> random_points;

	if (k > points.size()) {
		throw invalid_argument("k > points.size()");
	}

	for (int i = 0; i < k; i++) {
		int index = distribution(generator);
		random_points.push_back(points[index]);
	}

	return(random_points);
}

/**
 * @brief This function initializes the centroid of each cluster.
 * @param clusters Vector of clusters
 * @param random_points Vector of random points from dataset.
 * @return Void
 */
template <class T>
void init_cluster_centroid(vector<Cluster<T>>& clusters,
													 vector<Point<double>>& random_points) {
	int i = 0;

	// Initialize cluster centroids with random points from dataset
	for_each(clusters.begin(), clusters.end(),
					 [&random_points, &i](Cluster<T>& cluster) {
		cluster.set_centroid(random_points[i++]);
	});
}

/**
 * @brief This function implements the KMeans clustering algorithm.
 * @param k Number of clusters
 * @param points Vector of points
 * @param max_iterations Maximum number of iterations to run the clustering
 * algorithm.
 * @return Vector of clusters
 */
template <class T>
vector<Cluster<T>>
KMeans(int k, vector<Point<T>>& points, long max_iterations=1000) {
	vector<Cluster<T>> clusters;
	vector<Point<double>> random_points;

	// Create k clusters
	for (int i = 0; i < k; i++) {
		clusters.push_back(Cluster<T>(i));
	}

	// Choose k random points from dataset to initialize cluster centroids
	random_points = get_random_points<T>(k, points);

	// Initialize centroid of each cluster
	init_cluster_centroid<T>(clusters, random_points);

	return(clusters);
}

#endif //KMEANS_H
