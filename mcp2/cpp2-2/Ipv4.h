/*
 * Ipv4.h
 *
 *  Created on: 2019/05/20
 *      Author: hhhhh
 */

#ifndef IPV4_H_
#define IPV4_H_

#include <iostream>

class Ipv4 {
public:
	Ipv4(){this->addr = 0;}
	Ipv4(int n[4]){
		this->addr = ((n[0] << 24) | (n[1] << 16) | (n[2] << 8) | n[3]);
	};

	virtual ~Ipv4(){}

	Ipv4& operator=(Ipv4 const &a){
		addr = a.addr;
		return *this;
	}
	Ipv4& operator++(int){
		this->addr++;
		return *this;
	}

	friend bool operator<(Ipv4 const &a, Ipv4 const &b){
		return (a.addr < b.addr);
	}

	friend std::istream& operator>>(std::istream& is, Ipv4& a){
		int number[4];
		char dot;
		is >> number[0] >> dot >>
			  number[1] >> dot >>
			  number[2] >> dot >>
			  number[3];
		a = Ipv4(number);
		return is;
	}
	friend std::ostream& operator<<(std::ostream& os, Ipv4& a){
		os << ((a.addr >> 24) & 0xFF) << '.' <<
				((a.addr >> 16) & 0xFF) << '.' <<
				((a.addr >> 8) & 0xFF) << '.' <<
				(a.addr & 0xFF);

		return os;
	}

protected:
	uint32_t addr;
};

#endif /* IPV4_H_ */
