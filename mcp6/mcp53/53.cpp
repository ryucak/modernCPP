/*
 * 53.cpp
 *
 *  Created on: 2019/07/16
 *      Author: hhhhh
 */
#include <vector>
#include <algorithm>

double truncated_average(std::vector<int> values){
	double result = 0.0;
	int trim = values.size() * 5 / 100;
	int trimed_size = values.size() - trim * 2;

	std::sort(values.begin(),values.end());

	for (int i = 0; i < trimed_size; ++i) {
		result += (double)values[i];
	}
	return result / (double)trimed_size;
}



