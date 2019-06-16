/*
 * 35.cpp
 *
 *  Created on: 2019/06/16
 *      Author: hhhhh
 */
#include <string>
#include <filesystem>
#include <iostream>

using fs = std::filesystem;

void getDirSize(fs::path dir, size_t *size){

	for(auto e: fs::directory_iterator(dir)){
		if(e.is_directory()){
			*size += e.size();
			getDirSize(e.path(),size);
		}
	}
}


int main(int argc, char **argv) {
	size_t size = 0;
	getDirSize(fs::current_path(),size);

	std::cout << size <<std::endl;
}
