#include <iostream>
#include "string_castTemplate.h"

using std::endl;
using std::cout;
using string_castTemplate::string_cast;

int main()
{
	int i = string_cast<int>("123");
	double d = string_cast<double>("12.34");
//	bool b = string_cast<bool>("true");

	cout<< "Integer : " << i << endl;
	cout << "Double : " << d << endl;
//	cout << "Bool : "<< b << endl;
}
