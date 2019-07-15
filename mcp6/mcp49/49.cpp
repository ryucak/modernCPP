/*
 * 49.cpp
 *
 *  Created on: 2019/07/16
 *      Author: hhhhh
 */
#include <string>
#include <iostream>

void text_hist(std::string text){
	int hist[26] = {0};

	for(char ch:text){
		if(isalpha(ch)){
			hist[tolower(ch) - 'a']++;
		}
	}

	for (int i = 0; i < 26; ++i) {
		std::cout << i + 'a' << ':' << hist[i] << std::endl;
	}
}


