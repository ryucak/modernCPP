/*
 * 2_2.cpp
 *
 *  Created on: 2019/05/20
 *      Author: hhhhh
 */
#include "Ipv4.h"


int main(int argc, char **argv) {
	Ipv4 from,to;

	std::cin >> from >> to;

	for(Ipv4 i = from; i < to; i++){
		std::cout << i << "\n";
	}

	return 0;
}



