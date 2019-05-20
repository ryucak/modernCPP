/*
 * 1_8.cpp
 *
 *  Created on: 2019/05/07
 *      Author: hhhhh
 */
#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

bool isArmstrong3(int n) {
	int a,b,c;

	// a * 100 + b * 10 + c * 1,
	a = n / 100;
	b = (n % 100) / 10;
	c = n % 10;

	// a ^ 3 + b ^ 3 + c ^ 3
	return ((a*a*a + b*b*b + c*c*c) == n);

}

int main(int argc, char **argv) {
	for (int i = 100; i < 1000; ++i) {
		if(isArmstrong3(i)){
			cout << i << endl;
		}
	}
	return 0;
}
