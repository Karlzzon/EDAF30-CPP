#ifndef STRING_CASTTEMPLATE_H
#define STRING_CASTTEMPLATE_H
#include <sstream>
#include <stdexcept>

namespace string_castTemplate {
	
	template<typename T>
	T string_cast(const std::string& str){
	std::istringstream iss(str);
	T res;

	if(!(iss>>res) || !iss.eof()){
		throw std::invalid_argument("Invalid conversion from string to " + 
		std::string(typeid(T).name()));
	}
	return res;
}
}


#endif
