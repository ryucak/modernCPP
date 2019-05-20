/*
 * 1_9.cpp
 *
 *  Created on: 2019/05/07
 *      Author: hhhhh
 */
#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

int divisor(int n){
	for (int i = 2; i*i <= n; ++i) {
		if(n % i == 0){
			return i;
		}
	}
	return n;
}

int main(int argc, char **argv) {
	int n,m=0;

	cin >> n;

	while(true){
		 m = divisor(n);
		 cout << m << ',';
		 if(m == n){
			 break;
		 }
		 n /= m;
	 }

	return 0;
}
