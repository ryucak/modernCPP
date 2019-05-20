/*
 * 1_4.cpp
 *
 *  Created on: 2019/05/06
 *      Author: hhhhh
 */
#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

bool isPrime(unsigned int n) {
	switch (n) {
	case 0:
	case 1:
		return false;
	case 2:
		return true;
	default:
		break;
	}

	if (n % 2 == 0) {
		return false;
	}

// 0,1,2はもう見た。偶数は見なくていい。
	for (unsigned int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) {
			//memo[n] = -1;
			return false;
		}
	}

	return true;
}
int main(int argc, char **argv) {
	int n;

	cin >> n;

	if (n <= 0) {
		exit(-1);
	}

	for (int i = n - 1; i > 1; --i) {
		if (isPrime(i)) {
			cout << i;
			return 0;
		}
	}

	return -1;
}

