
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

class logger {
	fs::path logpath;
	std::ofstream logfile;
public:
	logger(std::string path) {
		logpath = fs::temp_directory_path() / (path + ".tmp");
		logfile.open(logpath.c_str(), std::ios::out | std::ios::trunc);
	}
	~
	logger() noexcept
	{
		logfile.close();
		fs::remove(logpath);
	}

	void save(fs::path const & path) {
		logfile.close();
		fs::rename(logpath, path);
		logpath.clear();
	}
	logger& operator<<(std::string const & message) {
		logfile << message.c_str() << '\n';
		return *this;
	}
};


