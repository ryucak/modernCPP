/*
 * 42.cpp
 *
 *  Created on: 2019/07/02
 *      Author: hhhhh
 */

// modernとは？

#include <iostream>

bool isLeap(int y){
	if(y % 400 == 0){
		return true;
	}
	if(y % 100 == 0){
		return false;
	}
	return (y % 4 == 0);
}

int monthDays(int m){
	switch(m){
	case 2:
		return 28;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	default:
		return 31;
	}
}

int dayOfYear(int y, int m, int d){
	int days = d;
	for (int i = 1; i < m; ++i) {
		days += monthDays(i);
	}
	if(isLeap(y) && m > 2){
		days++;
	}
	return days;
}

int weekOfYear(int y, int m, int d){
	return dayOfYear(y,m,d) / 7;
}

int main(int argc, char **argv) {
	std::cout << dayOfYear(2019,7,2) << std::endl;
	std::cout << weekOfYear(2019,7,2) << std::endl;
	std::cout << dayOfYear(2020,12,31) << std::endl;

	return 0;
}

