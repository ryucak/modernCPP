/*
 * 45.cpp
 *
 *  Created on: 2019/07/16
 *      Author: hhhhh
 */
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

template<class T, class Compare = std::less<typename std::vector<T>::value_type>>
class priority_queue {
	std::vector<T> data;
	Compare comparer;

public:
	bool empty() {
		return data.empty();
	}
	size_t size() {
		return data.size();
	}
	void push(T& value) {
		data.push_back(value);
		std::push_heap(std::begin(data), std::end(data), comparer);
	}
	void pop() {
		std::pop_heap(std::begin(data), std::end(data), comparer);
		data.pop_back();
	}
	T& top(){
		return data.front();
	}
};

int main() {
	priority_queue<int> q;
	for (int i : { 1, 5, 3, 1, 13, 21, 8 }) {
		q.push(i);
	}
	while (!q.empty()) {
		std::cout << q.top() << ' ';
		q.pop();
	}
}
