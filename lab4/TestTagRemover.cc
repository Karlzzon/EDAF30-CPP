#include <string>
#include "TagRemover.h"
#include <fstream>
#include <iostream>

using namespace std;

bool solCompare(string fname)
{
	TagRemover tr(fname);
	tr.print();
	
	ifstream sol("./htmlTestFiles/solutions/" + fname + "Sol.html");
	ifstream res("./htmlTestFiles/results/" + fname + "Res.html");
	
	if(!sol.is_open() || !res.is_open()){
		cout<< "couldnt open sol or res" << endl;
	}

	char c1, c2;

	while(sol.get(c1) && res.get(c2)){
		if(c1 != c2)
		{
			cout << "issue comparing characters" << endl;
			return false;
		}
	}
	return true;
}

int main()
{
	if (!solCompare("NoTag") || !solCompare("singleLineTag") || 
		!solCompare("singleLineMultipleTags") ||
		!solCompare("multiLineTag")||
		!solCompare("specialCharacters") ||
		!solCompare("test")
	){
		cout<< "Tests Failed"<< endl;
	}else{	
		cout<<"Tests Passed"<<endl;
	}
	return 0;
}
