#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"

using std::string;
using std::vector;

Dictionary::Dictionary() {
	string tmp;
	std::ifstream in("./words.txt");
	
	if(!in.is_open()){
		throw std::runtime_error("Unable to open file ./words.txt");
	}

	while(getline(in,tmp)){
		words.insert(tmp.substr(0, tmp.find_first_of(" ")));
	}
	in.close();
}

bool Dictionary::contains(const string& word) const {
	return words.find(word) != words.end();
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	return suggestions;
}
