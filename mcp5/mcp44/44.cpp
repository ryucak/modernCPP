/*
 * 44.cpp
 *
 *  Created on: 2019/07/02
 *      Author: hhhhh
 */
#include <iostream>

int zeller( int y, int m, int d )
{
    if( m < 3 ) {
        y--;
        m += 12;
    }
    return ( y + y/4 - y/100 + y/400 + ( 13*m + 8 )/5 + d )%7;
}


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

void cal(int y, int m){
	std::cout << "Sun Mon Tue Wed Thu Fri Sat" << std::endl;

	int lastDay = monthDays(m);
	if(isLeap(y) && m >= 2){
		lastDay++;
	}

	for (int i = 0; i < zeller(y,m,1); ++i) {
		std::cout << "    ";
	}
	for (int d = 1; d <= lastDay; ++d) {
		std::cout << ((d < 10)?"  ":" ") << d << " ";
		if(zeller(y,m,d) == 6){
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}

int main(int argc, char **argv) {
	cal(2019,7);
	cal(2020,2);
}
