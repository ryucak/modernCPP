/*
 * 33.cpp
 *
 *  Created on: 2019/06/16
 *      Author: hhhhh
 */
#include <string>
#include <vector>
#include <iostream>

struct procinfo
{
	int id;
	std::string name;
	std::string status;
	std::string account;
	size_t memory;
	std::string platform;
};

void printProcs(std::vector<procinfo> info){
	for (auto pi : info) {
		std::cout << pi.id << ' '
				  << pi.name << ' '
				  << pi.account << ' '
				  << pi.memory << ' '
				  << pi.platform
				;
	}
}
