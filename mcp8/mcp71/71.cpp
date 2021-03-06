/*
 * 71.cpp
 *
 *  Created on: 2019/09/17
 *      Author: hhhhh
 */

#include <list>
#include <vector>
#include <string>
#include <iostream>

enum class event{
	add_item = 0,
	remove_item,
	clear_all_item,
	copy_from_else,
};

class listner {
	std::vector<std::string> event_str = {
			"add",
			"remove",
			"clear",
			"copy"
	};
public:
	listner(){}
	listner(std::vector<std::string> msgs){
		event_str = msgs;
	}
	void event_handler(event evt){
		std::cout << event_str[static_cast<int>(evt)] << std::endl;
	}
};

class observer {
	std::list<listner> listners;
public:
	observer() {
		listners.clear();
	}
	void notify_event(event evt){
		for(auto lis : listners){
			lis.event_handler(evt);
		}
	}
	void add_listner(listner lis){
		listners.push_back(lis);
	}
};

template<typename T>
class observed_vector {
	observer obs;
	std::vector<T> vec;

public:
	observed_vector(){}
	observed_vector(const observed_vector &other){
		*this = other;
	}
	observed_vector& operator=(const observed_vector& other){
		if(this != &other){
			this->obs = other.obs;
			this->vec = other.vec;
		}
		obs.notify_event(event::copy_from_else);
		return *this;
	}
	observed_vector(std::vector<T>& v){
		this->vec = v;
	}
	void add_listner(listner l){
		obs.add_listner(l);
	}
	void push_back(T v){
		obs.notify_event(event::add_item);
		vec.push_back(v);
	}
	void pop_back(void){
		obs.notify_event(event::remove_item);
		vec.pop_back();
	}
	void clear(void){
		obs.notify_event(event::clear_all_item);
		vec.clear();
	}
	bool empty(void){
		return vec.empty();
	}
	int size(void){
		return vec.size();
	}
};

int main(int argc, char **argv) {
	observed_vector<int> ov;
	listner lis;
	listner lis2({
		"あど",
		"りむ",
		"くり",
		"こぴ",
	});
	ov.add_listner(lis);

	ov.push_back(1);
	ov.push_back(3);
	ov.push_back(4);

	if(!ov.empty()){
		std::cout << "has " << ov.size() <<  "item" << std::endl;
	}

	ov.add_listner(lis2);

	ov.pop_back();

	observed_vector<int> ov2 = ov;

	ov.clear();

	std::cout << "has " << ov2.size() <<  "item" << std::endl;
}

