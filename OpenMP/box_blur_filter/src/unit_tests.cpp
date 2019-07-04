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
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return(RUN_ALL_TESTS());
}
