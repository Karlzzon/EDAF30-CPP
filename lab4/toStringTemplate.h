#ifndef TOSTRINGTEMPLATE_H
#define TOSTRINGTEMPLATE_H
#include <string>
#include <sstream>

namespace toStringTemplate{
	
	template<typename T>
	std::string toString(const T& obj)
	{
		std::ostringstream oss;
		oss<< obj;
		return oss.str();
	}
}
#endif
