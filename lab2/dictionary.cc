#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"
#include <sstream>

using namespace std;

Dictionary::Dictionary() {
	string tmp;
	ifstream in("./words.txt");
	
	if(!in.is_open()){
		throw runtime_error("Unable to open file ./words.txt");
	}

	string name;
	vector<string> trigrams;
	while(getline(in,tmp)){
		name = tmp.substr(0,tmp.find_first_of(" ")); 
		
		istringstream iss(tmp.substr(tmp.find_first_of("0123456789")+1));
		string trigram;
		while(iss >> trigram){
			trigrams.push_back(trigram);
		}
		Word w(name, trigrams);	
		words[w.get_word().size()].push_back(w);
		trigrams.clear();
	}
	in.close();
}

bool Dictionary::contains(const string& word) const {
	for(auto w : words[word.size()]){
		if (w.get_word() == word){
			return true;
		}
	}
	return false;
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	add_trigram_suggestions(suggestions, word);
	return suggestions;
}

void Dictionary::add_trigram_suggestions(vector<string>& s, const string& w) const{	
	vector<string> trigrams;
	for(size_t i = 0; i + 2 < w.size(); ++i){			
		trigrams.push_back(w.substr(i,3));
	}
	sort(trigrams.begin(),trigrams.end());
	for(size_t i = w.size() - 1; i <= w.size() + 1; ++i){
		if(i < maxlen){
			for(const Word& word : words[i]){
				if(word.get_matches(trigrams) >= (trigrams.size()/2)){
					s.emplace_back(word.get_word());
				}
			}
		}
	}
}
