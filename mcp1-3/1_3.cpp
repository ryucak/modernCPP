/*
 * 1_3.cpp
 *
 *  Created on: 2019/05/06
 *      Author: hhhhh
 */

#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;

#define NUMBERS_MAX 16

int lcm(int m ,int n){
	int lcm = 0;

	for (int i = 1; i <= m; ++i) {
		lcm = n * i;
		if((lcm % m) == 0){
			break;
		}
	}
	return lcm;
}


int main(int argc, char **argv) {
	int n[NUMBERS_MAX];
	int cnt;
	string s;

	getline(cin,s);
	istringstream ss(s);

	for (cnt = 0; cnt < NUMBERS_MAX && ss.good(); ++cnt) {
		ss >> n[cnt];
		if(n[cnt] <= 0){
			exit(-1);
		}
		continue;
	}
	int l = n[0];
	for (int i = 1; i < cnt; ++i) {
		l = lcm(l,n[i]);
	}
	cout << l;
}
