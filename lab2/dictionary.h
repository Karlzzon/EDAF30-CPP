#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
#include <unordered_set>
#include "word.h"

class Dictionary {
public:
	Dictionary();
	bool contains(const std::string& word) const;
	std::vector<std::string> get_suggestions(const std::string& word) const;
private:
	static constexpr int maxlen{25};
	std::vector<Word> words[maxlen];
	void add_trigram_suggestions(std::vector<std::string>& s, const std::string& w) const;
	void rank_suggestions(std::vector<std::string>& s, const std::string& w) const;	
	void trim_suggestions(std::vector<std::string>& s) const;
};
#endif
