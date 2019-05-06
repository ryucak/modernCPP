/*
 * 1_14.cpp
 *
 *  Created on: 2019/05/07
 *      Author: hhhhh
 */
#include <iostream>
#include <cstdlib>
#include <climits>
#include <iterator>
#include <algorithm>

using namespace std;

bool valicateISBN(string code){

	int sum = 0;
	int weight = 10;

	for (auto it = cbegin(code); it != cend(code); ++it) {
		sum += it * weight;
		weight--;
	}

	return (sum == it);
}


