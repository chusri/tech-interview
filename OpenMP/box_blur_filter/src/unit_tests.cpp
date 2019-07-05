/**
 * @file unit_tests.cpp
 * @brief This file implements the unit tests.
 * @author Nawab Ali
 */

#include "Pixel.h"
#include "Image.h"
#include<gtest/gtest.h>

// Unit tests for Pixel class
TEST (BoxBlurFilterTest, PixelDefaultConstructor) {
	Pixel pixel(255);
	ASSERT_EQ(pixel.get_pixel(), 255);
}

TEST (BoxBlurFilterTest, PixelDefaultConstructorNoValue) {
	Pixel pixel;
	ASSERT_EQ(pixel.get_pixel(), 0);
}

TEST (BoxBlurFilterTest, PixelCopyConstructor) {
	Pixel pixel_1(255);
	Pixel pixel_2 = pixel_1;
	ASSERT_EQ(pixel_1, pixel_2);
}

TEST (BoxBlurFilterTest, PixelOverloadAssignmentOperator) {
	Pixel pixel_1(255);
	Pixel pixel_2(0);

	pixel_2 = pixel_1;
	ASSERT_EQ(pixel_1, pixel_2);
}

TEST (BoxBlurFilterTest, PixelSetGetRedChannel) {
	Pixel pixel;

	pixel.set_channel(rgba_channel::RED, 255);
	uint8_t value = pixel.get_channel(rgba_channel::RED);

	ASSERT_EQ(value, 255);
}

TEST (BoxBlurFilterTest, PixelSetGetGreenChannel) {
	Pixel pixel;

	pixel.set_channel(rgba_channel::GREEN, 5);
	uint8_t value = pixel.get_channel(rgba_channel::GREEN);

	ASSERT_EQ(value, 5);
}

TEST (BoxBlurFilterTest, PixelSetGetBlueChannel) {
	Pixel pixel;

	pixel.set_channel(rgba_channel::BLUE, 128);
	uint8_t value = pixel.get_channel(rgba_channel::BLUE);

	ASSERT_EQ(value, 128);
}

TEST (BoxBlurFilterTest, PixelSetGetAlphaChannel) {
	Pixel pixel;

	pixel.set_channel(rgba_channel::ALPHA, 64);
	uint8_t value = pixel.get_channel(rgba_channel::ALPHA);

	ASSERT_EQ(value, 64);
}

// Unit tests for Image class
TEST (BoxBlurFilterTest, ImageConstructor1) {
	Image image(4, 5);
	vector<vector<Pixel>> pixels;

	for (int i = 0; i < 5; i++) {
		vector<Pixel> v;
		for (int j = 0; j < 4; j++) {
			Pixel pixel;
			v.push_back(pixel);
		}
		pixels.push_back(v);
	}

	ASSERT_EQ(image.get_width(), 4);
	ASSERT_EQ(image.get_height(), 5);
	ASSERT_EQ(image.get_pixels(), pixels);
}

TEST (BoxBlurFilterTest, ImageConstructor2) {
	vector<vector<Pixel>> pixels;

	for (int i = 0; i < 5; i++) {
		vector<Pixel> v;
		for (int j = 0; j < 4; j++) {
			Pixel pixel;
			v.push_back(pixel);
		}
		pixels.push_back(v);
	}

	Image image(pixels);

	ASSERT_EQ(image.get_width(), 4);
	ASSERT_EQ(image.get_height(), 5);
	ASSERT_EQ(image.get_pixels(), pixels);
}

TEST (BoxBlurFilterTest, ImageConstructor3) {
	vector<vector<Pixel>> pixels;
	Image image(pixels);

	ASSERT_EQ(image.get_width(), 0);
	ASSERT_EQ(image.get_height(), 0);
	ASSERT_EQ(image.get_pixels(), pixels);
}

TEST (BoxBlurFilterTest, ImageCopyConstructor) {
	Image image1(4, 5);
	Image image2 = image1;

	ASSERT_EQ(image1, image2);
}

TEST (BoxBlurFilterTest, ImageOverloadAssignmentOperator) {
	Image image1(4, 5);
	Image image2;

	image2 = image1;

	ASSERT_EQ(image1, image2);
}

TEST (BoxBlurFilterTest, ImageSetPixel) {
	Pixel pixel(255);
	Image image(4, 5);

	image.set_pixel(2, 3, pixel);
	vector<vector<Pixel>> pixels = image.get_pixels();

	ASSERT_EQ(pixels[2][3], pixel);
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return(RUN_ALL_TESTS());
}
