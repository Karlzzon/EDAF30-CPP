#ifndef DECODE_H
#define DECODE_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Decode{
	public:
		void decodeFile(std::string filename);
	private:
		ifstream input;
		ofstream output;
		char toDeCode;
};
#endif
