/*
 * mcp31.cpp
 *
 *  Created on: 2019/06/02
 *      Author: hhhhh
 */

#include <iostream>
#include <string>
#include <regex>

std::string replace_date(std::string str){
	std::regex re("(\\d{2})[\\.-](\\d{2})[\\.-](\\d{4})");
	std::string fmt = "$3-$2-$1";

	return std::regex_replace(str,re,fmt);
}

int main(int argc, char **argv) {
	std::cout << replace_date("today is 01.12.2017!") << std::endl;
}

