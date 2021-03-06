/*
 * 41.cpp
 *
 *  Created on: 2019/07/02
 *      Author: hhhhh
 */
#include <iostream>

enum DayOfWeek{
	Sunday = 0,
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday
};


int zeller( int y, int m, int d )
{
    if( m < 3 ) {
        y--;
        m += 12;
    }
    return ( y + y/4 - y/100 + y/400 + ( 13*m + 8 )/5 + d )%7;
}

int main(int argc, char **argv) {
	std::cout << zeller(2019,7,2) << std::endl;
	std::cout << zeller(1981,2,26) << std::endl;
	std::cout << zeller(2000,1,1) << std::endl;
	std::cout << zeller(2019,6,29) << std::endl;

	return 0;
}
