/*
 * 56.cpp
 *
 *  Created on: 2019/08/05
 *      Author: hhhhh
 */
#include <string>
#include <vector>
#include <algorithm>

struct book {
	int id;
	std::string title;
	std::string author;
};
std::vector<book> books { { 101, "The C++ Programming Language",
		"Bjarne Stroustrup" }, { 203, "Effective Modern C++", "Scott Meyers" },
		{ 404, "The Modern C++ Programming Cookbook", "Marius Bancila" } };

template<typename T, typename A, typename F,
		typename R = typename std::decay<
						typename std::result_of<
						typename std::decay<F>::type&(
						typename std::vector<T, A>::const_reference)>::type>::type>

std::vector<R> select(std::vector<T, A> const & c, F&& f) {
	std::vector<R> v;
	std::transform(std::cbegin(c), std::cend(c), std::back_inserter(v),
			std::forward<F>(f));
	return v;
}
