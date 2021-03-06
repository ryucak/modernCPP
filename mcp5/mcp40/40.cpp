/*
 * 40.cpp
 *
 *  Created on: 2019/07/01
 *      Author: hhhhh
 */
#include <iostream>
#include <chrono>

using namespace std::chrono;

int durationDays(system_clock::time_point a, system_clock::time_point b){
	return duration_cast<hours>(a>b?a-b:b-a).count()/24;
}


int main(int argc, char **argv) {
	std::cout << durationDays(time_point<system_clock>(),system_clock::now()) << std::endl;
	std::cout << durationDays(system_clock::now(),time_point<system_clock>()) << std::endl;
	std::cout << durationDays(time_point<system_clock>(),time_point<system_clock>(seconds(60*60*24))) << std::endl;

	return 0;
}
