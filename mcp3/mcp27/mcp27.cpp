/*
 * mcp27.cpp
 *
 *  Created on: 2019/06/02
 *      Author: hhhhh
 */

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <cassert>

std::vector<std::string> split(std::string input, std::string delm){
	std::vector<std::string> ret = {};
	std::regex re("["+delm+"]+");
	std::smatch m;

	while(std::regex_search(input,m,re)){
		ret.push_back(m.prefix());
		input = m.suffix();
	}
	if(input.length() > 0){
		ret.push_back(input);
	}

	return ret;
}

int main(int argc, char **argv) {
	std::vector<std::string> expected{"this", "is", "a", "sample"};
	auto v = split("this,is a.sample!!", ",.! ");

	assert(expected == split("this is a sample", " "));
	assert(expected == v);

	std::cout << "OK!" << std::endl;

	return 0;

}
