/*
 * 1_11.cpp
 *
 *  Created on: 2019/05/07
 *      Author: hhhhh
 */
#include <iostream>
#include <cstdlib>
#include <climits>
#include <map>

using namespace std;

typedef struct {
	int th;
	const char *griph;
}node_t;
node_t config[] = {
		{1000, "M"},
		{900, "CM"},
		{500,  "D"},
		{400, "CD"},
		{100,  "C"},
		{ 90, "XC"},
		{ 50,  "L"},
		{ 40, "XL"},
		{ 10,  "X"},
		{  9, "IX"},
		{  5,  "V"},
		{  4, "IV"},
		{  1,  "I"},
};

int main(int argc, char **argv) {
	int n;

	cin >> n;

	if(n <= 0 || n >= 4000 ){
		exit(-1);
	}
	while(n > 0){
		for (unsigned i = 0; i < sizeof(config) / sizeof(node_t); ++i) {
			node_t *it = &config[i];

			if(n >= it->th){
				cout << it->griph;
				n -= it->th;
				break;
			}
		}
	}
	return 0;
}
