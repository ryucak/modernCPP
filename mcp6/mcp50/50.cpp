/*
 * 50.cpp
 *
 *  Created on: 2019/07/16
 *      Author: hhhhh
 */
#include <vector>
#include <string>

std::vector<std::string> filter_phone_numbers(
		std::vector<std::string> const & numbers,
		std::string const & countryCode) {
	std::vector<std::string> result;

	for(auto it:numbers){
		if(it.find(countryCode) || it.find('+' + countryCode)){
			result.push_back(it);
		}
	}
	return result;
}
