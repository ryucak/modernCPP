/*
 * mcp26.cpp
 *
 *  Created on: 2019/06/02
 *      Author: hhhhh
 */
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

template<class C>
std::string join(C con){
	std::stringstream ss;

	if(con.size() == 0){
		return "";
	}

	auto it = con.begin();
	for(it + 1; it != con.end(); ++it){
		ss << ' ' << *it;
	}
	return ss.str();
}

int main(int argc, char **argv) {
	std::vector<std::string> v1{ "this","is","an","example" };
	std::vector<std::string> v2{ "example" };
	std::vector<std::string> v3{ };

	std::cout << join(v1) << std::endl;
	std::cout << join(v2) << std::endl;
	std::cout << join(v3) << std::endl;

	return 0;
}
