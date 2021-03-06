/*
 * 51.cpp
 *
 *  Created on: 2019/07/16
 *      Author: hhhhh
 */
#include <vector>
#include <string>

std::vector<std::string> conv_phone_numbers(
		std::vector<std::string> const & numbers,
		std::string const & countryCode) {
	std::vector<std::string> result;

	for(auto it:numbers){
		std::string conv_str = "";

		if(it.find('+' + countryCode) == 0){
			conv_str = it;
		}else if(it.find(countryCode) == 0 ){
			conv_str = '+' + it;
		}else{
			conv_str = '+44' + it;
		}

		conv_str.replace(conv_str," ","");
	}
	return result;
}




