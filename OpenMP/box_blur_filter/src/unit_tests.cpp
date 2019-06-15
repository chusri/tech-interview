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

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return(RUN_ALL_TESTS());
}
