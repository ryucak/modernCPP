/*
 * 82.cpp
 *
 *  Created on: 2019/10/15
 *      Author: hhhhh
 */
#include <String>
#include <cstdlib>
#include <iostream>
#include "png++/png.hpp"

using namespace png;

int main(int argc, char **argv) {

	if(argc < 4) return -1;

	int width = std::atoi(argv[1]);
	int height = std::atoi(argv[2]);
	std::string filename = argv[3];

	std::cout << width << ',' << height << "->" << filename << std::endl;

	image<rgba_pixel> img("./input.png");

	img.resize(width,height);

	img.write(filename);

	return 0;
}



