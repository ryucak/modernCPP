/*
 * mcp30.cpp
 *
 *  Created on: 2019/06/02
 *      Author: hhhhh
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>

typedef std::vector<std::pair<std::string,std::string>> url_t;

url_t perse_url(std::string str){
	url_t url;
	std::regex re("^(\\w+):\\/\\/([\\w\\.]+)(:\\d+)?(\\/[\\w]+)*(\\?(.*))?(#(.*))?$");
	std::smatch m;
	if(std::regex_match(str,m,re)){
		url.push_back(std::make_pair("protocol",m.str(1)));
		url.push_back(std::make_pair("domain",m.str(2)));
		if(m[3].matched){
			url.push_back(std::make_pair("port",m.str(3)));
		}
		if(m[4].matched){
			url.push_back(std::make_pair("directory",m.str(4)));
		}
		if(m[5].matched){
			url.push_back(std::make_pair("query",m.str(6)));
		}
		if(m[7].matched){
			url.push_back(std::make_pair("flagment",m.str(8)));
		}
	}
	return url;
}

int main(int argc, char **argv) {
	url_t ggl = perse_url("https://www.google.com");
	url_t hoge = perse_url("https://www.google.com/search?q=hoge&oq=hoge&aqs=chrome..69i57j0j69i65j0l4.383j0j9&sourceid=chrome&ie=UTF-8");
	url_t flgm = perse_url("https://www.google.com#fufadsiddan");

	for (auto it = ggl.begin(); it != ggl.end(); ++it) {
		std::cout << it->first << ':' << it->second << std::endl;
	}
	for (auto it = hoge.begin(); it != hoge.end(); ++it) {
		std::cout << it->first << ':' << it->second << std::endl;
	}
	for (auto it = flgm.begin(); it != flgm.end(); ++it) {
		std::cout << it->first << ':' << it->second << std::endl;
	}



}
