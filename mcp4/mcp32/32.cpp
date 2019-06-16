/*
 * 32.cpp
 *
 *  Created on: 2019/06/16
 *      Author: hhhhh
 */
#include <iostream>
#include <vector>

void pascal(int len){
	std::vector<int> prev(1,1);

	for (int i = 0; i < len; ++i) {
		std::vector<int> line;
		for (int j = 0; j <= i; ++j) {
			if(j == 0){
				line.push_back(prev[j]);
			}else if( j == i){
				line.push_back(prev[j-1]);
			}else{
				line.push_back(prev[j] + prev[j-1]);
			}
			std::cout << line[j] << ' ';
		}
		prev = line;
		std::cout << std::endl;
	}
}

int main(int argc, char **argv) {
	pascal(10);
}
