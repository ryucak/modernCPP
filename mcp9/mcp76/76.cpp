/*
 * 76.cpp
 *
 *  Created on: 2019/09/30
 *      Author: hhhhh
 */
#include "nlohmann/json.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using json = nlohmann::json;

typedef struct {
	std::string ver;
	std::string integrity;
}depend_t;

int main(int argc, char **argv) {
	std::ifstream f("./package-lock.json");
	json j;

	f >> j;
	std::vector<depend_t> vd;

	for(auto elm : j.at("dependencies")){
		depend_t d;
		d.ver = elm.at("version").get<std::string>();
		d.integrity = elm.at("integrity").get<std::string>();
		vd.push_back(d);
	}

	for(auto d : vd){
		std::cout << d.ver << "," << d.integrity << std::endl;
	}
}

