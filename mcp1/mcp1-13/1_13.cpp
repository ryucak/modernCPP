/*
 * 1_13.cpp
 *
 *  Created on: 2019/05/07
 *      Author: hhhhh
 */
#include <iostream>
#include <random>

using namespace std;

#define MAX 1000000

int main(int argc, char **argv) {
	unsigned int inner = 0;
	double x,y;
	random_device rnd;
	mt19937 mt(rnd());
	uniform_real_distribution<> ur(-1.0,1.0);

	for (int i = 0; i < MAX; ++i) {
		x = ur(mt);
		y = ur(mt);

		if(x*x + y*y < 1.0){
			inner++;
		}
	}
	cout << static_cast<double>( 4 * inner )/ MAX;

	return 0;
}
