/*
 * 2_5.cpp
 *
 *  Created on: 2019/05/20
 *      Author: hhhhh
 */
#include <iostream>
#include <vector>
#include <initializer_list>
#include <iterator>

template<class Container,class First, class... Remain>
void push_back_multi(Container &c, First f, Remain ...args){
	c.push_back(f);

	for(First i: std::initializer_list<First>{args...}){
		c.push_back(i);
	}
}


int main(int argc, char **argv) {
	std::vector<int> hoge;

	push_back_multi(hoge,1,3,5,3,2,20);

	for(int i:hoge){
		std::cout << i << '\n';
	}

	return 0;
}
