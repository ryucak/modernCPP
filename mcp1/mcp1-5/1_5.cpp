/*
 * 1_5.cpp
 *
 *  Created on: 2019/05/06
 *      Author: hhhhh
 */

#include <iostream>
#include <cstdlib>
#include <climits>
#include <map>

using namespace std;

map<unsigned int,bool> memo;

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

	auto it = memo.find(n);
	if(it != memo.end()){
		return it->second;
	}

// 0,1,2はもう見た。偶数は見なくていい。
	for (unsigned int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) {
			memo.insert(make_pair(n,false));
			return false;
		}
	}
	memo.insert(make_pair(n,true));

	return true;
}

int main(int argc, char **argv) {
	int max;

	cin>>max;

	if(max <= 0){
		exit(-1);
	}

	for (int i = 0; i < max - 6; ++i) {
		//sexy?
		if(isPrime(i) && isPrime(i+6)){
			cout << i << ' ' << i+6 << endl;
		}
	}
	return 0;
}

