#pragma once

#include <string>
#include <vector>

using namespace std;

class Utilities
{
public:
	Utilities(void);
	~Utilities(void);

	static vector<string> Split(const char* str, char delimit = ' ');
};
