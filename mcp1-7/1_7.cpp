/*
 * 1_7.cpp
 *
 *  Created on: 2019/05/06
 *      Author: hhhhh
 */
#include <iostream>
#include <cstdlib>
#include <climits>
#include <map>

using namespace std;

#define MAX 1000000

map<int,int> amic; //amicable numbers.

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
	for (int i = 0; i < MAX; ++i) {
		amic.emplace(i,sumOfDivisor(i));
	}

	for (int i = 0; i < MAX; ++i) {
		int sum = sumOfDivisor(i);
		if(i == sum ){
			continue;
		}
		auto it = amic.find(sum);
		if(it != amic.end() && it->second == i && amic.at(i) == it->first){
			cout << it->second <<','<< it->first << endl;
			amic.erase(it->first);
			amic.erase(it->second);
		}
	}

}



