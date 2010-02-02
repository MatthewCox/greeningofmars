#pragma once

#include <vector>
#include <string>

class Utilities
{
public:
	Utilities(void);
	~Utilities(void);

	static std::vector<std::string> Split(const char* str, char delimit = ' ');
};
