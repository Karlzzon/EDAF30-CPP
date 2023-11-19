#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ifstream input("/usr/share/dict/words");
	ofstream output;
	output.open("words.txt");

	vector<string> trigrams;
	
	string word;
	while(getline(input,word))
	{	
			transform(word.begin(), word.end(), word.begin(), ::tolower);
			output<<word << " ";
			trigrams.clear();

			for(string::size_type i=0; i+2<word.size();++i){
				trigrams.push_back(word.substr(i,3));
			}			
			sort(trigrams.begin(),trigrams.end());
			trigrams.erase(unique(trigrams.begin(), trigrams.end()), trigrams.end());
			
			auto x = trigrams.size();
			output << x << " ";

			for ( auto x : trigrams){
				output << x <<" ";	
			}
			output<< "\n";	
	}
	output.close();

}
