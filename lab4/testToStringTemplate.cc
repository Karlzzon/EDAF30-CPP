#include <iostream>
#include "date.h"
#include "toStringTemplate.h"

using std::endl;
using std::cout;
using toStringTemplate::toString;
/*
bool test_date(){
	Date d(2015,05,10);
	cout<< toString(d);
	return true;
}
*/

int main()
{
//	test_date();

	int i = 5;
	cout<<"testing int : " << toString(i)<<endl;

	bool b = true;

	cout<< "testing bool : " << toString(b)<<endl;

	double d = 1.234;

	cout << "testing double : " <<toString(d)<<endl;
	
}
