/*
 * mcp29.cpp
 *
 *  Created on: 2019/06/02
 *      Author: hhhhh
 */
#include <iostream>
#include <regex>
#include <string>
#include <vector>

static std::regex re("[A-Z]{3}-[A-Z]{2} \\d{3,4}");

bool is_number_plate(std::string str){
	return std::regex_match(str,re);
}

std::vector<std::string> number_plate_substr(std::string str){
	std::vector<std::string> ret = {};
	std::smatch m;

	while(std::regex_search(str,m,re)){
		ret.push_back(m.str(0));
		str = m.suffix();
	}

	return ret;
}


int main(int argc, char **argv) {
	std::vector<std::string> tst = {"ABC-DE 123","ABC-DE 1234","ABC-DE 12345","abc-de 1234"};
	std::vector<std::string> v = number_plate_substr("AAA-AA 123qwe-ty 1234 ABC-DE 123456..XYZ-WW 0001");


	for (auto it = tst.begin(); it < tst.end(); ++it) {
		std::cout << is_number_plate(*it) << std::endl;
	}
	for (auto it = v.begin(); it < v.end(); ++it) {
		std::cout << *it << std::endl;
	}
}
