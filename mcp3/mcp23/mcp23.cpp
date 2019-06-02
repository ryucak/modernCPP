/*
 * mcp23.cpp
 *
 *  Created on: 2019/06/02
 *      Author: hhhhh
 */
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <algorithm>
#include <cassert>

template<class C>
std::string toStrTmpl(C container){
	std::stringstream ss;
	for (auto it = container.begin(); it != container.end(); ++it) {
		ss << std::hex << static_cast<int>(*it);
	}
	return ss.str();
}

unsigned char toHex(char c){
	if('0' <= c && c <= '9' ){
		return c - '0';
	}else if ('a' <= c && c <= 'z' ){
		return c - 'a';
	}else if ('A' <= c && c <= 'Z'){
		return c - 'A';
	}else{
		assert(false);
	}
	return 0;
}

void strToHex(std::string str){
	for (auto it = str.begin(); it != str.end(); ++it) {
		std::cout << toHex(*it);
	}
	std::cout << std::endl;
}

int main(int argc, char **argv) {
	std::vector<unsigned char> v{ 0xBA, 0xAD, 0xF0, 0x0D };
	std::array<unsigned char, 6> a{{ 1,2,3,4,5,6 }};

	std::string vStr = toStrTmpl(v);
	std::string aStr = toStrTmpl(a);

	std::cout << vStr << std::endl;
	std::cout << aStr << std::endl;

	strToHex(vStr);
	strToHex(aStr);

}

