/*
 * 34.cpp
 *
 *  Created on: 2019/06/16
 *      Author: hhhhh
 */
#include <string>
#include <regex>
#include <iostream>
#include <fstream>
#include <sstream>
bool isValidline(std::string line){
	std::regex re(R"(^\s*$)");
	return !std::regex_match(line,re);
}
void deleteBlank(std::string path){
	std::ifstream input(path);
	std::ofstream output("out_" + path);
	std::string line;
	while(getline(input,line)){
		if(isValidline(line)){
			output << line << std::endl;
		}
	}
}
int main(int argc, char **argv) {
	deleteBlank("34.cpp");
}
