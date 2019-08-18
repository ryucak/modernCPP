/*
 * 65.cpp
 *
 *  Created on: 2019/08/19
 *      Author: hhhhh
 */

#include <mutex>
#include <string>
#include <iostream>
#include <thread>
#include <vector>

class Logger {
	std::mutex *m;

public:
	Logger() { m = new std::mutex(); }

	void log(std::string msg) {
		m->lock();
		std::cout << msg << std::endl;
		m->unlock();
	}
};



int main(int argc, char **argv) {
	Logger logger;
	std::vector<std::thread> threads;

	for (int id = 0; id < 100; ++id) {
		threads.emplace_back([id,&logger](){
			for (int i = 0; i < 100; ++i) {
				logger.log(std::to_string(id) + " thread " + std::to_string(id));
			}
		});
	}

	for(auto & th : threads){
		th.join();
	}
}

