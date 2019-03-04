/**
 * @file Point.h
 * @brief This file implements the Point class.
 * @author Nawab Ali
 */

#ifndef POINT_H
#define POINT_H

#include<vector>
#include<cassert>
#include<iostream>

using namespace std;

/**
 * @class Point
 * @brief This class implements a point in a n-dimensional space.
 */
template <class T>
class Point {
	public:
		/**
		 * @brief Constructor for the Point class.
		 * @param dimensions Number of dimensions in space.
		 * @return None Constructor does not return.
		 */
		Point(int dimensions);

		/**
		 * @brief Constructor for the Point class.
		 * @param dimensions Number of dimensions in space.
		 * @param coordinates Coordinates of the point in n-dimensional space.
		 * @return None Constructor does not return.
		 */
		Point(int dimensions, vector<T> coordinates);

		/**
		 * @brief Copy Constructor for the Point class.
		 * @param point Point object.
		 * @return None Constructor does not return.
		 */
		Point(const Point<T>& point);

		/**
		 * @brief Overload the assignment operator for the Point class.
		 * @param point Point object.
		 * @return Reference to a Point object.
		 */
		Point<T>& operator=(const Point<T>& point);

		/**
		 * @brief Overload the << operator for the Point class.
		 * @param ostream ostream object.
		 * @param point Point object.
		 * @return Reference to ostream object.
		 */
		friend ostream& operator<<(ostream& out, const Point<T>& point) {
			for_each(point.coordinates.begin(), point.coordinates.end(), [out](T e) {
				out << e << " ";
			});

			return(out);
		}

		/**
		 * @brief Getter method for number of dimensions.
		 * @param void
		 * @return Number of dimensions in space.
		 */
		int get_dimensions(void) const;

		/**
		 * @brief Getter method for coordinates of point.
		 * @param void
		 * @return Coordinates of point in n-dimensional space.
		 */
		vector<T> get_coordinates(void) const;

		/**
		 * @brief Setter method for coordinates of point.
		 * @param coordinates Coordinates of point in n-dimensional space.
		 * @return void
		 */
		void set_coordinates(const vector<T> coordinates);

	private:
		int dimensions;
		vector<T> coordinates;
};

// Constructor with 1 argument
template <class T>
Point<T>::Point(int dimensions): dimensions(dimensions) {
	coordinates = vector<T>(dimensions);
}

// Constructor with 2 arguments
template <class T>
Point<T>::Point(int dimensions, vector<T> coordinates):
								dimensions(dimensions), coordinates(coordinates) {
	assert(coordinates.size() == dimensions);
}

// Copy Constructor
template <class T>
Point<T>::Point(const Point<T>& point):
								Point(point.dimensions, point.coordinates) {}

// Overloaded assignment operator
template <class T>
Point<T>& Point<T>::operator=(const Point<T>& point) {
	dimensions = point.dimensions;
 	coordinates = point.coordinates;

	return(*this);
}

// Getter method for number of dimensions
template <class T>
int Point<T>::get_dimensions(void) const {
	return(dimensions);
}

// Getter method for coordinates of point
template <class T>
vector<T> Point<T>::get_coordinates(void) const {
	return(coordinates);
}

// Setter method for coordinates of point
template <class T>
void Point<T>::set_coordinates(const vector<T> coordinates) {
	assert(coordinates.size() == dimensions);
	this->coordinates = coordinates;
}

#endif //POINT_H
