/**
 * @file Pixel.h
 * @brief This file implements a Pixel class.
 * @author Nawab Ali
 */

#ifndef PIXEL_H
#define PIXEL_H

#include<cstdint>
#include<iostream>

using namespace std;

typedef union {
	uint32_t value;
	uint8_t bytes[4];
} pixel_t;

/**
 * @class Pixel
 * @brief This class implements a pixel in an image.
 */

class Pixel {
	public:
		/**
		 * @brief Constructor for the Pixel class
		 * @param rgba Pixel value
		 * @return None
		 */
		Pixel(uint32_t rgba=0);

		/**
		 * @brief Copy Constructor for the Pixel class
		 * @param pixel Reference to Pixel object
		 * @return None
		 */
		Pixel(const Pixel& pixel);

		/**
		 * @brief Overload the assignment operator
		 * @param pixel Reference to Pixel object
		 * @return Reference to Pixel object
		 */
		Pixel& operator=(const Pixel& pixel);

		/**
		 * @brief Overload the == operator
		 * @param pixel Reference to Pixel object
		 * @return True or False
		 */
		bool operator==(const Pixel& pixel) const;

		/**
		 * @brief Overload the << operator
		 * @param ostream Reference to ostream object
		 * @param pixel Reference to Pixel object
		 * @return Reference to ostream object
		 */
		friend ostream& operator<<(ostream& out, const Pixel& pixel) {
			out << pixel.get_red_channel() << "," << pixel.get_green_channel() << "," <<
						 pixel.get_blue_channel() << "," << pixel.get_alpha_channel() << "," <<
						 pixel.get_rgba() << endl;
			return(out);
		}

		/**
		 * @brief Getter method for rgba value of pixel
		 * @param void
		 * @return RGBA value of pixel
		 */
		uint32_t get_rgba(void) const;

		/**
		 * @brief Getter method for red channel of pixel
		 * @param void
		 * @return Red channel of pixel
		 */
		uint8_t get_red_channel(void) const;

		/**
		 * @brief Getter method for green channel of pixel
		 * @param void
		 * @return Green channel of pixel
		 */
		uint8_t get_green_channel(void) const;

		/**
		 * @brief Getter method for blue channel of pixel
		 * @param void
		 * @return Blue channel of pixel
		 */
		uint8_t get_blue_channel(void) const;

		/**
		 * @brief Getter method for alpha channel of pixel
		 * @param void
		 * @return Alpha channel of pixel
		 */
		uint8_t get_alpha_channel(void) const;

		/**
		 * @brief Setter method for rgba value of pixel
		 * @param rgba RGBA value of pixel
		 * @return void
		 */
		void set_rgba(const uint32_t rgba);

		/**
		 * @brief Setter method for red channel of pixel
		 * @param red Red channel of pixel
		 * @return void
		 */
		void set_red_channel(const uint8_t red);

		/**
		 * @brief Setter method for green channel of pixel
		 * @param green Green channel of pixel
		 * @return void
		 */
		void set_green_channel(const uint8_t green);

		/**
		 * @brief Setter method for blue channel of pixel
		 * @param blue Blue channel of pixel
		 * @return void
		 */
		void set_blue_channel(const uint8_t blue);

		/**
		 * @brief Setter method for alpha channel of pixel
		 * @param alpha Alpha channel of pixel
		 * @return void
		 */
		void set_alpha_channel(const uint8_t alpha);

	private:
		pixel_t rgba;
};

Pixel::Pixel(uint32_t rgba) {
	this->rgba.value = rgba;
}

uint32_t Pixel::get_rgba(void) const {
	return(rgba.value);
}

#endif //PIXEL_H
