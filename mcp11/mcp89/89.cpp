/*
 * 89.cpp
 *
 *  Created on: 2019/11/03
 *      Author: hhhhh
 */
#include <iostream>
#include <string>
#include <functional>

class vignere {
	std::string key;
protected:
	static char element(char k) {
		return (k - 'A');
	}
	static char to_char(char c) {
		return c % 26 + 'A';
	}

	std::string crypt(std::string in, std::function<char(char, char)> f) {
		std::string out;

		for (size_t i = 0; i < in.length(); ++i) {
			char c = in[i];
			if (isalpha(c) && isupper(c)) {
				c = f(c, key[i % key.length()]);
			}
			out.push_back(c);
		}
		return out;
	}
public:
	vignere(std::string key) {
		this->key = key;
	}
	std::string encrypt(std::string clr) {
		return crypt(clr, [](char c,char k) {return to_char(c + element(k));});
	}
	std::string decrypt(std::string cpr) {
		return crypt(cpr, [](char c,char k) {return to_char(c - element(k));});
	}
};

int main(int argc, char **argv) {
	std::string hoge;
	vignere vig("ARM");

	std::cin >> hoge;
	std::string hoge_crypt = vig.encrypt(hoge);
	std::cout << hoge_crypt << std::endl;
	std::cout << vig.decrypt(hoge_crypt) << std::endl;

	return 0;
}

