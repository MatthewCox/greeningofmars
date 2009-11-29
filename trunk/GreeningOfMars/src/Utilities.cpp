#include "Utilities.h"

Utilities::Utilities(void)
{
}

Utilities::~Utilities(void)
{
}

vector<string> Utilities::Split(const char* str, char delimit)
{
	vector<string> result;

	while(true)
	{
		const char* begin = str;

		while(*str != delimit && *str)
		{
			str++;
		}

		result.push_back(string(begin, str));

		if (0 == *str++)
		{
			break;
		}
	}
	return result;
}