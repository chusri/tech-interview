/**
 * @file Image.h
 * @brief This file implements an Image class.
 * @author Nawab Ali
 */

#ifndef IMAGE_H
#define IMAGE_H

#include "Pixel.h"
#include<vector>
#include<cstdint>
#include<iostream>

using namespace std;

/**
 * @class Image
 * @brief This class implements a 2-dimensional image.
 */

class Image {
	public:
		/**
		 * @brief Constructor for the Image class
		 * @param width Image width
		 * @param height Image height
		 * @return None
		 */
		Image(unsigned long width=0, unsigned long height=0);

		/**
		 * @brief Constructor for the Image class
		 * @param pixels Image pixels
		 * @return None
		 */
		Image(vector<vector<Pixel>> pixels);

		/**
		 * @brief Copy Constructor for the Image class
		 * @param image Reference to Image object
		 * @return None
		 */
		Image(const Image& image);

		/**
		 * @brief Overload the assignment operator
		 * @param image Reference to Image object
		 * @return Reference to Image object
		 */
		Image& operator=(const Image& image);

		/**
		 * @brief Overload the == operator
		 * @param image Reference to Image object
		 * @return True or False
		 */
		bool operator==(const Image& image) const;

		/**
		 * @brief Overload the << operator
		 * @param ostream Reference to ostream object
		 * @param image Reference to Image object
		 * @return Reference to ostream object
		 */
		friend ostream& operator<<(ostream& out, const Image& image) {
			return(out);
		}

		/**
		 * @brief Getter method for image width
		 * @param void
		 * @return image width
		 */
		unsigned long get_width(void) const;

		/**
		 * @brief Getter method for image height
		 * @param void
		 * @return image height
		 */
		unsigned long get_height(void) const;

		/**
		 * @brief Getter method for image pixels
		 * @param void
		 * @return image pixels
		 */
		vector<vector<Pixel>> get_pixels(void) const;

		/**
		 * @brief Setter method for image pixels
		 * @param pixels image pixels
		 * @return void
		 */
		void set_pixels(const vector<vector<Pixel>> pixels);

	private:
		unsigned long width;
		unsigned long height;
		vector<vector<Pixel>> pixels;
};

#endif //IMAGE_H
