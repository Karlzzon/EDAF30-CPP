#include <string>
#include <vector>
#include "word.h"
#include <algorithm>

using std::vector;
using std::string;

Word::Word(const string& w, const vector<string>& t) : word{w}, trigrams{t} {}

string Word::get_word() const {
	return word;
}

unsigned int Word::get_matches(const vector<string>& t) const {
	vector<string> matches;

	//förutsättar att bägge vektorerna är sorterade. 
	std::set_intersection(
		trigrams.begin(), trigrams.end(),
		t.begin(), t.end(),
		std::back_inserter(matches)
	);
	return matches.size();
}
