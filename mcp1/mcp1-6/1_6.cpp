/*
 * 1_6.cpp
 *
 *  Created on: 2019/05/06
 *      Author: hhhhh
 */

#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

int sumOfDivisor(int n){
	int sum = 1;

	for (int i = 2; i * i <= n; ++i) {
		if(n % i == 0){
			sum += i;
			if(n / i != i){
				sum += n / i;
			}
		}
	}
	return sum;
}

int main(int argc, char **argv) {
	int max;
	int sum;

	cin >> max;

	if(max <= 0){
		exit(-1);
	}

	for (int i = 0; i < max; ++i) {
		sum = sumOfDivisor(i);

		if(sum > i*2){
			cout << i << ',' << sum - i * 2 << endl;
		}
	}
	return 0;
}

