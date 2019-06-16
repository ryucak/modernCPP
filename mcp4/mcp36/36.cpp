/*
 * 36.cpp
 *
 *  Created on: 2019/06/16
 *      Author: hhhhh
 */
#include <filesystem>

namespace fs = std::experimental::filesystem;
namespace ch = std::chrono;

bool isOld(fs::path const & path, int duration) {
	auto ftime = fs::last_write_time(path).time_since_epoch();
	auto now = (ch::system_clock::now() - duration).time_since_epoch();
	return now - ftime  > 0;
}


void deleteOldFile(fs::path dir, size_t *size){

	for(auto e: fs::directory_iterator(dir)){
		if(isOld(e.path(), 100)){
			fs::remove(e);
		}
	}
}
