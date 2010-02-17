#include "Utilities.h"

#include <vector>
#include <string>

std::vector<std::string> Utilities::Split(const char* str, char delimit)
{
	std::vector<std::string> result;

	while(true)
	{
		const char* begin = str;

		while(*str != delimit && *str)
		{
			str++;
		}

		result.push_back(std::string(begin, str));

		if (0 == *str++)
		{
			break;
		}
	}
	return result;
}