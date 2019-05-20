/*
 * 2_6.cpp
 *
 *  Created on: 2019/05/21
 *      Author: hhhhh
 */
#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <initializer_list>
#include <algorithm>

void assert(bool exsp){
	if(exsp){
		std::cout << "pass.\n";
	}else{
		std::cout << "fail!!\n";
		exit(-1);
	}
}
template<class C, class T>
bool contains(C & c, T & val){
	return (std::end(c) != std::find(std::begin(c),std::end(c),val));
}

template<class Container, class... Args>
bool contains_any(Container c, Args... args){
	return (... || contains(c,args));
}

template<class Container, class... Args>
bool contains_all(Container c, Args... args){
	return (... && contains(c,args));
}

template<class Container, class... Args>
bool contains_none(Container c, Args... args){
	return !(... || contains(c,args));
}

int main(int argc, char **argv) {
	std::vector<int> v { 1, 2, 3, 4, 5, 6 };
	assert(contains_any(v, 0, 3, 30));
	std::array<int, 6> a { { 1, 2, 3, 4, 5, 6 } };
	assert(contains_all(a, 1, 3, 5, 6));
	std::list<int> l { 1, 2, 3, 4, 5, 6 };
	assert(!contains_none(l, 0, 6));

	return 0;
}
