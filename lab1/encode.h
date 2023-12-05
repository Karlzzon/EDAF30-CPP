#ifndef ENCODE_H
#define  ENCODE_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Encode{
	public:
		void encodeFile(std::string filename);
	private:
		ifstream input;
		ofstream output;
		char toCode;

};
#endif
