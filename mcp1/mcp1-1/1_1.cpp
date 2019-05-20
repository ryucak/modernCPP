/*
 * 1_1.cpp
 *
 *  Created on: 2019/04/27
 *      Author: hhhhh
 */

#include <iostream>

int main(int argc, char **argv) {
	int sum=0,max=0;

	std::cin >> max;

	for (int i = 0; i < max; ++i) {
		if(i%3==0||i%5==0){
			std::cout << i << ",";
			sum += i;
		}
	}

	std::cout << "\n" << sum << "\n";
}

