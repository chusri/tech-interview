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
#include<algorithm>

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
		 * @brief Setter method for image pixel
		 * @param i index into 2-dim image
		 * @param j index into 2-dim image
		 * @param pixel image pixel
		 * @return void
		 */
		void set_pixel(const unsigned long i, const unsigned long j, const Pixel pixel);

		/**
		 * @brief Destructor for the Image class
		 * @return None
		 */
		~Image();

	private:
		unsigned long width;
		unsigned long height;
		vector<vector<Pixel>> pixels;
};

Image::Image(unsigned long width, unsigned long height): width(width), height(height) {
	for (int i = 0; i < height; i++) {
		vector<Pixel> v;
		for (int j = 0; j < width; j++) {
			Pixel pixel;
			v.push_back(pixel);
		}
		pixels.push_back(v);
	}
}

Image::Image(vector<vector<Pixel>> pixels): pixels(pixels) {
	height = pixels.size();

	if (height == 0) {
		width = 0;
	} else {
		width = pixels[0].size();
	}
}

Image::Image(const Image& image): width(image.width), height(image.height), pixels(image.pixels) {}

Image& Image::operator=(const Image& image) {
	width = image.width;
	height = image.height;
	pixels = image.pixels;

	return(*this);
}

bool Image::operator==(const Image& image) const {
	return (width == image.width && height == image.height && pixels == image.pixels);
}

unsigned long Image::get_width(void) const {
	return width;
}

unsigned long Image::get_height(void) const {
	return height;
}

vector<vector<Pixel>> Image::get_pixels(void) const {
	return pixels;
}

void Image::set_pixel(const unsigned long i, const unsigned long j, const Pixel pixel) {
	if (i >= height || j >= width) {
		throw invalid_argument("i >= height || j >= width");
	}
	else {
		pixels[i][j] = pixel;
	}
}

Image::~Image() {
	for_each (pixels.begin(), pixels.end(), [](vector<Pixel> v) {v.clear();});
	pixels.clear();
}

#endif //IMAGE_H
