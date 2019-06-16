/*
 * 37.cpp
 *
 *  Created on: 2019/06/16
 *      Author: hhhhh
 */

#include <filesystem>
#include <regex>
#include <iostream>

namespase fs = std::filesystem;

void findFile(fs::path dir, std::regex re){
	for(auto e: fs::file_iterator(dir)){
		if(std::regex_match(e.filenamename(),re)){
			std::cout << e.filename();
		}
	}
}

int main(int argc, char **argv) {
	std::regex re(R"(.*\.cpp)");
	findFile(fs::current_path(),re);
}
