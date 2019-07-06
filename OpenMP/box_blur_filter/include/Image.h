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
		 * @param height Image height
		 * @param width Image width
		 * @return None
		 */
		Image(unsigned long height=0, unsigned long width=0);

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
			unsigned long height = image.get_height();
			unsigned long width = image.get_width();

			out << height << ", " << width << endl;
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					out << image.get_pixel(i, j).get_pixel() << " ";
				}
				out << endl;
			}
			return(out);
		}

		/**
		 * @brief Getter method for image height
		 * @param void
		 * @return image height
		 */
		unsigned long get_height(void) const;

		/**
		 * @brief Getter method for image width
		 * @param void
		 * @return image width
		 */
		unsigned long get_width(void) const;

		/**
		 * @brief Getter method for image pixels
		 * @param void
		 * @return image pixels
		 */
		vector<vector<Pixel>> get_pixels(void) const;

		/**
		 * @brief Getter method for image pixel
		 * @param i index into 2-dim image
		 * @param j index into 2-dim image
		 * @return image pixel
		 */
		Pixel get_pixel(const unsigned long i, const unsigned long j) const;

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
		unsigned long height;
		unsigned long width;
		vector<vector<Pixel>> pixels;
};

Image::Image(unsigned long height, unsigned long width): height(height), width(width) {
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

Image::Image(const Image& image): height(image.height), width(image.width), pixels(image.pixels) {}

Image& Image::operator=(const Image& image) {
	height = image.height;
	width = image.width;
	pixels = image.pixels;

	return(*this);
}

bool Image::operator==(const Image& image) const {
	return (height == image.height && width == image.width && pixels == image.pixels);
}

unsigned long Image::get_height(void) const {
	return height;
}

unsigned long Image::get_width(void) const {
	return width;
}

vector<vector<Pixel>> Image::get_pixels(void) const {
	return pixels;
}

Pixel Image::get_pixel(const unsigned long i, const unsigned long j) const {
	if (i >= height || j >= width) {
		throw invalid_argument("i >= height || j >= width");
	}
	else {
		return (pixels[i][j]);
	}
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
