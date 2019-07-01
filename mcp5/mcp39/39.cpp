/*
 * 39.cpp
 *
 *  Created on: 2019/07/01
 *      Author: hhhhh
 */

#include <iostream>
#include <chrono>
#include <thread>

using namespace std::chrono;
template <typename Duration>
struct FuncTimer_t{
	template <typename Func,typename... Args>
	static Duration elapse(Func target,Args... args){
		auto start = system_clock::now();
		target(args...);
		return duration_cast<Duration>(system_clock::now() - start);
	}
};

void hoge(int a,int b){
	std::this_thread::sleep_for(seconds(2));
}

int main(int argc, char **argv) {
	std::cout << FuncTimer_t<seconds>::elapse(hoge,1,2).count() << std::endl;
	std::cout << FuncTimer_t<milliseconds>::elapse(hoge,1,2).count() << std::endl;
	std::cout << FuncTimer_t<microseconds>::elapse(hoge,1,2).count() << std::endl;
	std::cout << FuncTimer_t<nanoseconds>::elapse(hoge,1,2).count() << std::endl;

	return 0;
}
