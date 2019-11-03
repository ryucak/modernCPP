/*
 * 88.cpp
 *
 *  Created on: 2019/11/03
 *      Author: hhhhh
 */

#include <string>
#include <iostream>

std::string caesar(std::string instr, int shift)
{
	std::string outstr = "";

	for(auto c : instr){
		if(isalpha(c) && isupper(c)){
			c += shift;
		}
		outstr.append(&c);
	}
	return outstr;
}

int main(int argc, char **argv) {
	std::string hoge;

	std::cin >> hoge;

	std::cout << caesar(hoge,2) << std::endl;

	return 0;
}


