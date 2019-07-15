#include <vector>
#include <iostream>

template <class T>
class ring_buffer
{
	std::vector<T> data;
	size_t size;
	int head;
	int next(){
		return (head + 1) % size;
	}
	int tail(){
		return (head + data.size() - size + 1);
	}
public:
	explicit ring_buffer(size_t const s) : data(s) {size = 0;head=-1;}
	void push(T item){
		head = next();
		data[head] = item;
		if(size < data.size()){
			size++;
		}
	}
	T pop(){
		auto pos = tail();
		size--;
		return data[pos];
	}
};
