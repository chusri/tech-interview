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
		 * @return None
		 */
		Cluster(void);

		/**
		 * @brief Constructor for the Cluster class.
		 * @param id Cluster id.
		 * @return None
		 */
		Cluster(int id);

		/**
		 * @brief Constructor for the Cluster class.
		 * @param id Cluster id.
		 * @param points Vector of points in the cluster.
		 * @return None
		 */
		Cluster(int id, vector<Point<T>> points);

		/**
		 * @brief Copy Constructor for the Cluster class.
		 * @param cluster Cluster object.
		 * @return None
		 */
		Cluster(const Cluster<T>& cluster);

		/**
		 * @brief Overload the assignment operator for the Cluster class.
		 * @param cluster Cluster object.
		 * @return Reference to a Cluster object.
		 */
		Cluster<T>& operator=(const Cluster<T>& cluster);

		/**
		 * @brief Overload the == operator for the Cluster class.
		 * @param cluster Cluster object.
		 * @return True or False.
		 */
		bool operator==(const Cluster<T>& cluster) const;

		/**
		 * @brief Overload the << operator for the Cluster class.
		 * @param ostream ostream object.
		 * @param cluster Cluster object.
		 * @return Reference to ostream object.
		 */
		friend ostream& operator<<(ostream& out, const Cluster<T>& cluster) {
			out << "Cluster id: " << cluster.id << endl;
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
		 * @brief Getter method for cluster centroid.
		 * @param void
		 * @return cluster centroid.
		 */
		Point<double> get_centroid(void) const;

		/**
		 * @brief Getter method for points in a cluster.
		 * @param void
		 * @return vector of points.
		 */
		vector<Point<T>> get_points(void) const;

		/**
		 * @brief Setter method for cluster id.
		 * @param id cluster id.
		 * @return void
		 */
		void set_id(const int id);

		/**
		 * @brief Setter method for cluster centroid.
		 * @param centroid cluster centroid.
		 * @return void
		 */
		void set_centroid(const Point<double> centroid);

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

		/**
		 * @brief Return number of points in cluster.
		 * @param void
		 * @return Number of points in cluster.
		 */
		long get_num_points(void) const;

	private:
		int id;
		Point<double> centroid;
		vector<Point<T>> points;
		void calculate_centroid(void);
};

// Constructor
template <class T>
Cluster<T>::Cluster(void): id(-1) {}

// Constructor
template <class T>
Cluster<T>::Cluster(int id): id(id) {}

// Constructor
template <class T>
Cluster<T>::Cluster(int id, vector<Point<T>> points): id(id), points(points) {
	calculate_centroid();
}

// Copy Constructor
template <class T>
Cluster<T>::Cluster(const Cluster<T>& cluster): Cluster(cluster.id,
										cluster.points) {
	centroid = cluster.centroid;
}

// Overload assignment operator
template <class T>
Cluster<T>& Cluster<T>::operator=(const Cluster<T>& cluster) {
 	id = cluster.id;
 	centroid = cluster.centroid;
 	points = cluster.points;

	return(*this);
}

// Overload == operator
template <class T>
bool Cluster<T>::operator==(const Cluster<T>& cluster) const {
	return(id == cluster.id && points == cluster.points);
}

// Getter method for cluster id
template <class T>
int Cluster<T>::get_id(void) const {
	return(id);
}

// Getter method for cluster centroid
template <class T>
Point<double> Cluster<T>::get_centroid(void) const {
	return(centroid);
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

// Setter method for cluster centroid
template <class T>
void Cluster<T>::set_centroid(const Point<double> centroid) {
	this->centroid = centroid;
}

// Setter method for points
template <class T>
void Cluster<T>::set_points(const vector<Point<T>> points) {
	this->points = points;
	calculate_centroid();
}

// Add point to cluster
template <class T>
void Cluster<T>::add_point(const Point<T> point) {
	points.push_back(point);
	calculate_centroid();
}

// Remove point from cluster
template <class T>
void Cluster<T>::remove_point(const Point<T> point) {
	points.erase(remove(points.begin(), points.end(), point), points.end());
	calculate_centroid();
}

// Return number of points in cluster
template <class T>
long Cluster<T>::get_num_points(void) const {
	return(points.size());
}

// Calculate the centroid of the points in the cluster
template <class T>
void Cluster<T>::calculate_centroid(void) {}

#endif //CLUSTER_H
