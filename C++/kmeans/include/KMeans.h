/**
 * @file KMeans.h
 * @brief This file implements the KMeans clustering algorithm.
 * @author Nawab Ali
 */

#ifndef KMEANS_H
#define KMEANS_H

#include<vector>
#include "Point.h"
#include "Cluster.h"

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
KMeans(int k, vector<Point<T>> points, long max_iterations=1000) {
	vector<Cluster<T>> clusters(k);

	return(clusters);
}

/**
 * @brief This function initializes the centroid of each cluster.
 * @param clusters Vector of clusters
 * @param random_points Vector of random points from dataset.
 * @return Void
 */
template <class T>
void init_cluster_centroid(vector<Cluster<T>>& clusters,
													 vector<Point<T>>& random_points) {
	int i = 0;

	// Initialize cluster centroids with random points from dataset
	for_each(clusters.begin(), clusters.end(),
					 [&random_points, &i](Cluster<T> cluster) {
		cout << i << endl;
		cluster.set_centroid(random_points[i++]);
		cout << cluster.get_centroid() << endl;
	});
}

#endif //KMEANS_H
