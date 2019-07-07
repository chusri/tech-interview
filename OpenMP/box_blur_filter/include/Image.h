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
			for (unsigned long row = 0; row < height; row++) {
				for (unsigned long col = 0; col < width; col++) {
					out << image.get_pixel(row, col).get_pixel() << " ";
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
		 * @param row index into image row
		 * @param col index into image column
		 * @return image pixel
		 */
		Pixel get_pixel(const unsigned long row, const unsigned long col) const;

		/**
		 * @brief Setter method for image pixel
		 * @param row index into image row
		 * @param col index into image column
		 * @param pixel image pixel
		 * @return void
		 */
		void set_pixel(const unsigned long row, const unsigned long col, const Pixel pixel);

		/**
		 * @brief Destructor for the Image class
		 * @return None
		 */
		~Image();

	private:
		unsigned long height;
		unsigned long width;
		vector<vector<Pixel>> pixels;

		/**
		 * @brief Calculate new value of pixel at x,y by averaging pixel values
		 * from radius pixels
		 * @param row index into image row
		 * @param col index into image column
		 * @param radius range of neighboring pixels to calculate new pixel value
		 * @return New pixel
		 */
		Pixel box_blur_kernel(const unsigned long row, const unsigned long col, const unsigned long radius);

		/**
		 * @brief Calculate new value of pixels for row
		 * @param row index into image row
		 * @param radius range of neighboring pixels to calculate new pixel value
		 * @return vector of blurred pixels
		 */
		vector<Pixel> blur_image_row(const unsigned long row, const unsigned long radius);
};

Image::Image(unsigned long height, unsigned long width): height(height), width(width) {
	for (unsigned long row = 0; row < height; row++) {
		vector<Pixel> v;
		for (unsigned long col = 0; col < width; col++) {
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

Pixel Image::get_pixel(const unsigned long row, const unsigned long col) const {
	if (row >= height || col >= width) {
		throw invalid_argument("row >= height || col >= width");
	}
	else {
		return (pixels[row][col]);
	}
}

void Image::set_pixel(const unsigned long row, const unsigned long col, const Pixel pixel) {
	if (row >= height || col >= width) {
		throw invalid_argument("row >= height || col >= width");
	}
	else {
		pixels[row][col] = pixel;
	}
}

Image::~Image() {
	for_each (pixels.begin(), pixels.end(), [](vector<Pixel> v) {v.clear();});
	pixels.clear();
}

Pixel
Image::box_blur_kernel(const unsigned long row, const unsigned long col, const unsigned long radius) {
	Pixel pixel;
	unsigned long num_elements = 0;
	uint32_t red = 0, green = 0, blue = 0, alpha = 0;
	unsigned long row_start = min((row-radius), static_cast<unsigned long>(0));
	unsigned long row_end = min((row+radius), height);
	unsigned long col_start = min((col-radius), static_cast<unsigned long>(0));
	unsigned long col_end = min((col+radius), width);

	for (unsigned long k = row_start; k < row_end; k++) {
		for (unsigned long l = col_start; l < col_end; l++) {
			red += pixels[k][l].get_channel(rgba_channel::RED);
			green += pixels[k][l].get_channel(rgba_channel::GREEN);
			blue += pixels[k][l].get_channel(rgba_channel::BLUE);
			alpha += pixels[k][l].get_channel(rgba_channel::ALPHA);
		}
	}

	num_elements = (row_end-row_start+1)*(col_end-col_start+1);
	pixel.set_channel(rgba_channel::RED, static_cast<uint8_t>(red/num_elements));
	pixel.set_channel(rgba_channel::GREEN, static_cast<uint8_t>(green/num_elements));
	pixel.set_channel(rgba_channel::BLUE, static_cast<uint8_t>(blue/num_elements));
	pixel.set_channel(rgba_channel::ALPHA, static_cast<uint8_t>(alpha/num_elements));

	return (pixel);
}

vector<Pixel> Image::blur_image_row(const unsigned long row, const unsigned long radius) {
	vector<Pixel> pixels;

	if (row >= height) {
		throw invalid_argument("row >= height");
	}
	else {
		for (unsigned long col = 0; col < width; col++) {
			pixels.push_back(box_blur_kernel(row, col, radius));
		}
	}

	return (pixels);
}

#endif //IMAGE_H
