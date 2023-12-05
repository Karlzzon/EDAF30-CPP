#include "TagRemover.h"
#include <fstream>

using namespace std;

void TagRemover::removeTags(string& res)
{
	while(res.find('<') != string::npos)
	{
		int start = res.find_first_of('<') -1;
		int stop = res.find_first_of('>') + 1;
		res.erase(start,(stop-start));
	}
}
void TagRemover::translateSpecials(string& res)
{
	while(res.find('&') != string::npos && res.find(';') != string::npos)
	{
		string::size_type start = res.find_first_of('&');
		string::size_type stop = res.find_first_of(';') + 1;
		string translation(1,specialCharacters.at(res.substr(start, (stop-start))));
		res.replace(start,(stop-start), translation);	
	}
}

TagRemover::TagRemover(string& filename): fname(filename)
{
	ifstream in("./htmlTestFiles/" + fname + ".html");
	if(!in.is_open()){
		cout<< "could not open input file " + fname <<endl;
	}else{
		res.assign((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
		removeTags(res);
		translateSpecials(res);
	}
}

void TagRemover::print()
{
	ofstream out("./htmlTestFiles/results/" + fname + "Res.html");
	if(out.is_open()){
		out<<res;
	}else{
		cout<< "could not open output file"<<endl;
	}
}

