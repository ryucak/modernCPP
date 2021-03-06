/*
 * 48.cpp
 *
 *  Created on: 2019/07/16
 *      Author: hhhhh
 */
#include <algorithm>
#include <vector>
#include <map>

template <typename T>
std::vector<std::pair<T, size_t>> mode(std::vector<T> const & range)
{
	std::map<T,size_t> cnt;

	for (auto it:range) {
		cnt[it]++;
	}
	std::pair<T,size_t> max(range[0],0);

	for(auto it:cnt){
		if(it.second > max.second){
			max = it;
		}
	}

	std::vector<std::pair<T, size_t>> result;

	for(auto it:cnt){
		if(it.second == max.second){
			result.push_back(it);
		}
	}

	return result;
}

