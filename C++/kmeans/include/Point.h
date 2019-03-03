/**
 * @file Point.h
 * @brief This file implements the Point class.
 * @author Nawab Ali
 */

#ifndef POINT_H
#define POINT_H

#include<vector>

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

	private:
		int dimensions;
		vector<T> coordinates;
};

Point::Point(int dimensions): dimensions(dimensions) {}

template <class T>
Point::Point(int dimensions, vector<T> coordinates) :
						 dimensions(dimensions), coordinates(coordinates) {}

int Point::get_dimensions(void) const {
	return(dimensions);
}

template <class T>
vector<T> Point::get_coordinates(void) const {
	return(coordinates);
}

#endif //POINT_H
