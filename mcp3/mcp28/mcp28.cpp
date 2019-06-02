/*
 * mcp28.cpp
 *
 *  Created on: 2019/06/02
 *      Author: hhhhh
 */
#include <iostream>
#include <string>
#include <regex>

bool is_palindrome(std::string test){
	if(test.length() < 2) return false;
	for (size_t i = 0; i < test.length() / 2; ++i) {
		if(test[i] != test[test.length() - i -1]){
			return false;
		}
	}
	return true;
}

std::string longest_palindrome(std::string str){
	std::string longest = "";
	size_t max = 0;
	for (size_t pos = 0; pos < str.length() - 1; ++pos) {
		for (size_t len = str.length() - pos; len > max; --len) {
			std::string sub = str.substr(pos,len);
			if(is_palindrome(sub)){
				max = sub.length();
				longest = sub;
			}
		}
	}
	return longest;
}


int main(int argc, char **argv) {

	std::cout << longest_palindrome("hoge") << std::endl;
	std::cout << longest_palindrome("hogea") << std::endl;
	std::cout << longest_palindrome("sahararahnide") << std::endl;

	return 0;
}


