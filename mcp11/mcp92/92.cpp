/*
 * 92.cpp
 *
 *  Created on: 2019/11/03
 *      Author: hhhhh
 */
//https://create.stephan-brumme.com/hash-library/
#include "md5.h"
#include "sha1.h"
#include "sha256.h"

#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char **argv) {

	std::string path;
	std::cin >> path;
	std::ifstream f(path, std::ios::binary | std::ios::ate);

	if (!f.is_open()) {
		std::cout << "ugh!!" << std::endl;
	}

	auto size = f.tellg();
	std::string data(size, '\0');
	f.seekg(0);
	f.read(&data[0], size);

	MD5 md5;
	SHA1 sha1;
	SHA256 sha256;

	md5.add(&data[0], size);
	sha1.add(&data[0], size);
	sha256.add(&data[0], size);

	std::cout << "md5:" << md5.getHash() << std::endl;
	std::cout << "sha1:" << sha1.getHash() << std::endl;
	std::cout << "sha256:" << sha256.getHash() << std::endl;

	return 0;
}

/*
 Debug/mcp92.exe
 md5:70ed6c19a5c2f6deccf655ff43e1ee88
 sha1:53050d90d6bd2562838a6faa89d9bd2ed22b1e79
 sha256:ce132fa8038f5f468f3358809fa0a2fc8291b6586a9b0f94ba9429e70919a688
 */

/*
 Microsoft Windows [Version 10.0.18362.418]
 (c) 2019 Microsoft Corporation. All rights reserved.

 D:\MyDocument\GitHub\modernCPP\mcp11\mcp92\Debug>certutil -hashfile mcp92.exe MD5
 MD5 ハッシュ (対象 mcp92.exe):
 70ed6c19a5c2f6deccf655ff43e1ee88
 CertUtil: -hashfile コマンドは正常に完了しました。

 D:\MyDocument\GitHub\modernCPP\mcp11\mcp92\Debug>certutil -hashfile mcp92.exe SHA1
 SHA1 ハッシュ (対象 mcp92.exe):
 53050d90d6bd2562838a6faa89d9bd2ed22b1e79
 CertUtil: -hashfile コマンドは正常に完了しました。

 D:\MyDocument\GitHub\modernCPP\mcp11\mcp92\Debug>certutil -hashfile mcp92.exe SHA256
 SHA256 ハッシュ (対象 mcp92.exe):
 ce132fa8038f5f468f3358809fa0a2fc8291b6586a9b0f94ba9429e70919a688
 CertUtil: -hashfile コマンドは正常に完了しました。
 */
