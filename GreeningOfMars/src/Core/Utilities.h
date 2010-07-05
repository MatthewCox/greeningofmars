#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <sstream>

class Utilities
{
public:
	static std::vector<std::string> Split(const char* str, char delimit = ' ');
	template<typename T> static inline std::string to_string(const T& v)
	{
		std::ostringstream stm;
		stm << v;
		return stm.str();
	};

};
