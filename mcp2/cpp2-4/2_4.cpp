/*
 * 2_4.cpp
 *
 *  Created on: 2019/05/20
 *      Author: hhhhh
 */
#include <initializer_list>
#include <iostream>

template <typename Compair, typename First, typename... Remain> First min(Compair func, First f,Remain ...args){
	First min = f;

	for (First i: std::initializer_list<First>{args...}) {
		min = func(min,i);
	}

	return min;
}

int main(int argc, char **argv) {
	auto c = [](int a,int b){return (a<b?a:b);};
	std::cout << min(c,1,2,3,-2,155);
}
