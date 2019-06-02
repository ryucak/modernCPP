/*
 * mcp25.cpp
 *
 *  Created on: 2019/06/02
 *      Author: hhhhh
 */

#include <iostream>
#include <regex>
#include <string>

std::string capitalize_word(std::string word){
	std::string capitalized_word = "";
	char ch = '0';

	auto it = word.begin();
	ch = *it;

	if( 'a' <= *it  && *it <= 'z'){
		ch += 'A' - 'a';
	}
	capitalized_word.push_back(ch);
	for(++it; it != word.end(); ++it){
		ch = *it;
		if( 'A' <= *it  && *it <= 'Z'){
			ch += 'a' - 'A';
		}
		capitalized_word.push_back(ch);
	}
	return capitalized_word;
}


std::string capitalize(std::string input){
	const std::regex re("(\\S+)\\s");
	std::smatch m;
	std::string out = "";

	while(std::regex_search(input,m,re)){
		out += capitalize_word(m.str());
		input = m.suffix();
	}
	out += capitalize_word(input);

	return out;
}

int main() {
	std::cout << capitalize("the c++ challenger") << std::endl;
	std::cout << capitalize("THIS IS an ExamplE, should wORk!" ) << std::endl;
	return 0;
}


