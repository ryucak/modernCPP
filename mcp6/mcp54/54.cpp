/*
 * 54.cpp
 *
 *  Created on: 2019/07/16
 *      Author: hhhhh
 */
#include <vector>

template<typename Input, typename Output>
void pairwise(Input begin, Input end, Output result) {
	auto it = begin;
	while (it != end) {
		auto const v1 = *it++;
		if (it == end)
			break;
		auto const v2 = *it++;
		result++ = std::make_pair(v1, v2);
	}
}
template<typename T>
std::vector<std::pair<T, T>> pairwise(std::vector<T> const & range) {
	std::vector<std::pair<T, T>> result;
	pairwise(std::cbegin(range), std::cend(range), std::back_inserter(result));
	return result;
}

