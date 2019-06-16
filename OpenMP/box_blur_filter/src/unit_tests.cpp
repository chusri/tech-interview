/**
 * @file unit_tests.cpp
 * @brief This file implements the unit tests.
 * @author Nawab Ali
 */

#include "Pixel.h"
#include<gtest/gtest.h>

// Unit tests for Pixel class
TEST (BoxBlurFilterTest, PixelDefaultConstructor) {
	Pixel pixel(255);
	ASSERT_EQ(pixel.get_rgba(), 255);
}

TEST (BoxBlurFilterTest, PixelDefaultConstructorNoValue) {
	Pixel pixel;
	ASSERT_EQ(pixel.get_rgba(), 0);
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

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return(RUN_ALL_TESTS());
}
