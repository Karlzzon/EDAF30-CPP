#ifndef TAGREMOVER_H
#define TAGREMOVER_H

#include <unordered_map>
#include <string>
#include <iostream>

const static std::unordered_map<std::string, char> specialCharacters
{
	{"&lt;", '<'},
	{"&gt;", '>'},
	{"&nbsp;", ' '},
	{"&amp;", '&'}
};

class TagRemover
	{
	public:
		TagRemover() = delete;
		TagRemover(std::string&);
		void print();
	private:
		std::string res;
		std::string fname;
		void removeTags(std::string&);
		void translateSpecials(std::string&);
}; 

#endif
