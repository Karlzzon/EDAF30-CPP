#include <string>
#include <vector>
#include "word.h"
#include <algorithm>

using std::vector;
using std::string;
using std::unordered_set;

Word::Word(const string& w, const vector<string>& t) : word{w}, trigrams{t} {}

string Word::get_word() const {
	return word;
}

unsigned int Word::get_matches(const vector<string>& t) const {
	int c = 0;

	for(const auto &s : t )
	{
		if(find(trigrams.begin(), trigrams.end(), s) != trigrams.end())
		{
			c++;
		}
	}
	return c;
}
