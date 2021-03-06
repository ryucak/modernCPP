/*
 * 55.cpp
 *
 *  Created on: 2019/07/16
 *      Author: hhhhh
 */
#include <vector>

template<typename Input1, typename Input2, typename Output>
void zip(Input1 const begin1, Input1 const end1, Input2 const begin2,
		Input2 const end2, Output result) {
	auto it1 = begin1;
	auto it2 = begin2;
	while (it1 != end1 && it2 != end2) {
		result++ = std::make_pair(*it1++, *it2++);
	}
}
template<typename T, typename U>
std::vector<std::pair<T, U>> zip(std::vector<T> const & range1,
		std::vector<U> const & range2) {
	std::vector<std::pair<T, U>> result;
	zip(std::cbegin(range1), std::cend(range1), std::cbegin(range2),
			std::cend(range2), std::back_inserter(result));
	return result;
}
