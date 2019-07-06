/**
 * @file main.cpp
 * @brief This file implements the main thread of execution.
 * @author Nawab Ali
 */

#include "Pixel.h"
#include "Image.h"
#include<iostream>

using namespace std;

int main(int argc, char** argv) {
	Pixel pixel(122255);
	Image image(3, 4);

	cout << pixel;
	cout << image;

	return(0);
}
