/*
 * 1_10.cpp
 *
 *  Created on: 2019/05/07
 *      Author: hhhhh
 */

#include <iostream>
#include <cstdlib>
#include <climits>
#include <bitset>

using namespace std;

#define CAST_5BIT(x) static_cast<std::bitset<5>>((x))

unsigned int grayEncode(unsigned int b){
	return ((b) ^ ((b) >> 1));
}

unsigned int grayDecode(unsigned int g){
	unsigned int d = g;
	while(g){
		g >>= 1;
		d ^= g;
	}
	return d;
}

int main(int argc, char **argv) {

	for (unsigned int b = 0; b < 0b11111; ++b) {
		auto g = grayEncode(b);
		auto d = grayDecode(g);
		cout << CAST_5BIT(b)
				<< ','
				<< CAST_5BIT(g)
				<< ','
				<< CAST_5BIT(d)
				<< endl;
	}

	return 0;
}
