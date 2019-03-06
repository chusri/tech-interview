/**
 * @file Cluster.h
 * @brief This file implements the Cluster class.
 * @author Nawab Ali
 */

#ifndef CLUSTER_H
#define CLUSTER_H

#include "Point.h"
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

/**
 * @class Cluster
 * @brief This class implements a cluster of points.
 */
template <class T>
class Cluster {
	public:
		/**
		 * @brief Constructor for the Cluster class.
		 * @return None Constructor does not return.
		 */
		Cluster(void);

		/**
		 * @brief Constructor for the Cluster class.
		 * @param id Cluster id.
		 * @return None Constructor does not return.
		 */
		Cluster(int id);

		/**
		 * @brief Constructor for the Cluster class.
		 * @param id Cluster id.
		 * @param points Vector of points in the cluster.
		 * @return None Constructor does not return.
		 */
		Cluster(int id, vector<Point<T>> points);

		/**
		 * @brief Copy Constructor for the Cluster class.
		 * @param point Cluster object.
		 * @return None Constructor does not return.
		 */
		Cluster(const Cluster<T>& point);

		/**
		 * @brief Overload the assignment operator for the Cluster class.
		 * @param point Cluster object.
		 * @return Reference to a Cluster object.
		 */
		Cluster<T>& operator=(const Cluster<T>& point);

		/**
		 * @brief Overload the << operator for the Cluster class.
		 * @param ostream ostream object.
		 * @param point Cluster object.
		 * @return Reference to ostream object.
		 */
		friend ostream& operator<<(ostream& out, const Cluster<T>& cluster) {
			for_each(cluster.points.begin(), cluster.points.end(),
							[&out](const Point<T> p) {
				out << p << " " << endl;
			});

			return(out);
		}

		/**
		 * @brief Getter method for cluster id.
		 * @param void
		 * @return cluster id.
		 */
		int get_id(void) const;

		/**
		 * @brief Getter method for points in a cluster.
		 * @param void
		 * @return vector of points.
		 */
		vector<T> get_points(void) const;

		/**
		 * @brief Setter method for cluster id.
		 * @param id cluster id.
		 * @return void
		 */
		void set_id(const int id);

		/**
		 * @brief Setter method for points in a cluster.
		 * @param points vector of points.
		 * @return void
		 */
		void set_points(const vector<Point<T>> points);

		/**
		 * @brief Add a point to a cluster.
		 * @param point Point in a n-dimensional space.
		 * @return void
		 */
		void add_point(const Point<T> point);

		/**
		 * @brief Remove point from cluster.
		 * @param point Point in a n-dimensional space.
		 * @return void
		 */
		void remove_point(const Point<T> point);

	private:
		int id;
		vector<Point<T>> points;
};

// Constructor
template <class T>
Cluster<T>::Cluster(void): id(-1) {}

// Constructor
template <class T>
Cluster<T>::Cluster(int id): id(id) {}

// Constructor
template <class T>
Cluster<T>::Cluster(int id, vector<Point<T>> points): id(id), points(points) {}

// Copy Constructor
template <class T>
Cluster<T>::Cluster(const Cluster<T>& cluster):
										Cluster(cluster.id, cluster.points) {}

// Overloaded assignment operator
template <class T>
Cluster<T>& Cluster<T>::operator=(const Cluster<T>& cluster) {
 	id = cluster.id;
 	points = cluster.points;

	return(*this);
}

// Getter method for cluster id
template <class T>
int Cluster<T>::get_id(void) const {
	return(id);
}

// Getter method for cluster points
template <class T>
vector<Point<T>> Cluster<T>::get_points(void) const {
	return(points);
}

// Setter method for cluster id
template <class T>
void Cluster<T>::set_id(const int id) {
	this->id = id;
}

// Setter method for points
template <class T>
void Cluster<T>::set_points(const vector<Point<T>> points) {
	this->points = points;
}

// Add point to cluster
void Cluster<T>::add_point(const Point<T> point) {
	points.push_back(point);
}

// Remove point from cluster
void Cluster<T>::remove_point(const Point<T> point) {
	points.erase(remove(points.begin(), points.end(), point), points.end());
}

#endif //CLUSTER_H
