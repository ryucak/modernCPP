/*
 * 1_2.cpp
 *
 *  Created on: 2019/05/06
 *      Author: hhhhh
 */
#include <iostream>
#include <cstdlib>

#define min(a,b) ((a)<(b)?(a):(b))

int main(int argc, char **argv) {
	int a, b, mod;

	std::cin >> a >> b;

	if (a < 0 || b < 0) {
		std::exit(-1);
	}

	if (a > b) {
		//swap
		mod = a;
		a = b;
		b = mod;
	}
	// a < b.
	while (a > 0) {
		mod = b%a;
		b = a;
		a = mod;
	}
	std::cout << b;
}
