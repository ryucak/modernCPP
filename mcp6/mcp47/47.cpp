/*
 * 47.cpp
 *
 *  Created on: 2019/07/16
 *      Author: hhhhh
 */
template<typename T>
class double_buffer {
	std::vector<T> rdbuf;
	std::vector<T> wrbuf;

public:
	explicit double_buffer(size_t const size) :
			rdbuf(size), wrbuf(size) {
	}
	size_t size() const noexcept {
		return rdbuf.size();
	}
	void write(T const * const ptr, size_t const size) {
		auto length = std::min(size, wrbuf.size());
		std::copy(ptr, ptr + length, std::begin(wrbuf));
		wrbuf.swap(rdbuf);
	}
	template<class Output>
	void read(Output it) const {
		std::copy(std::cbegin(rdbuf), std::cend(rdbuf), it);
	}
	T* data() const {
		return rdbuf.data();
	}
	T& operator[](size_t const pos) {
		return rdbuf[pos];
	}
	T const& operator[](size_t const pos) const {
		return rdbuf[pos];
	}
	void swap(double_buffer other) {
		std::swap(rdbuf, other.rdbuf);
		std::swap(wrbuf, other.wrbuf);
	}
};
