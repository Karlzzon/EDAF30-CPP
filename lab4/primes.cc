#include <string>
#include <iostream>

using namespace std;

int main()
{
	string primes(100000, 'P');
	primes.replace(0,2, "CC");

	string::size_type current = 0;
	string::size_type toMark = 0; 
	
	while((current = primes.find('P', current +1 )) != string::npos){
		toMark = current;
		while(toMark < primes.size())
		{	
			toMark +=current;
			if(toMark<primes.size()){
				primes.replace(toMark,1,"C");
			}
		}

	}
	cout<< primes.substr(0,200)<< endl;
	cout<< primes.rfind('P')<<endl;
}


