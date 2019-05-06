/*
 * 1_12.cpp
 *
 *  Created on: 2019/05/07
 *      Author: hhhhh
 */
#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

#define MAX 1000000

unsigned long number = 0;
unsigned long length = 0;

unsigned long memo[MAX] = {0};

unsigned long long collatz(unsigned long long n, unsigned long long l){
	unsigned long long m = n;
	if(memo[m] != 0){
		return memo[m] + l;
	}
	while(n != 1){
		if(n%2==0){
			n /= 2;
		}else {
			n *= 3;
			n++;
		}
		l++;
	}
	memo[m] = l;
	return l;
}


int main(int argc, char **argv) {
	for (int i = 1; i < MAX; ++i) {
		unsigned long long len = collatz(i,0);
		if(len > length){
			length = len;
			number = i;
		}
	}
	cout << length << ',' << number << endl;
	return 0;
}


