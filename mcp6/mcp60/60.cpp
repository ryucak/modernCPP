/*
 * 60.cpp
 *
 *  Created on: 2019/08/05
 *      Author: hhhhh
 */
#include <set>
#include <vector>
#include <iostream>

class cell{
	bool alive;
	std::set<cell>	neighbors;
public:
	int count();
	void next_gen(bool alive) {this->alive = alive;}
	void display(void) {
		if (this->alive) {
			std::cout << '*';
		} else {
			std::cout << ' ';
		}
	}
	bool judge(void){
		switch(count()){
		case 2:
			if(alive) return true;
			break;
		case 3:
			return true;
		}
		return false;
	}
};

int cell::count(void){
	int cnt;
	for (cell c :neighbors) {
		if(c.alive){
			cnt++;
		}
	}
	return cnt;
}

#define WIDTH 50
#define HEIGHT 50


int main(int argc, char **argv) {
	auto map = std::vector<cell>(WIDTH,HEIGHT);
	bool doa = std::vector<bool>(WIDTH,HEIGHT);

	for (int i = 0; i < WIDTH; ++i) {
		for (int j = 0; j < HEIGHT; ++j) {
			//隣接セルをセット
		}
	}

	while(true){
		for (int i = 0; i < WIDTH; ++i) {
			for (int j = 0; j < HEIGHT; ++j) {
				map[i,j].display();
				doa[i,j] = map[i,j].judge();
			}
		}
		for (int i = 0; i < WIDTH; ++i) {
			for (int j = 0; j < HEIGHT; ++j) {
				map[i,j].next_gen(doa[i,j]);
			}
		}
	}
}
