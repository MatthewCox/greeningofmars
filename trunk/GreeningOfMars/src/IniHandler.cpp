#include "IniHandler.h"

#include <Windows.h>

#include "Utilities.h"

char* IniHandler::fileName = ".\\settings.ini";

void IniHandler::SetFileName(char* p_fileName)
{
	fileName = p_fileName;
}

int IniHandler::ReadInt(char* p_section, char* p_key, int p_defaultValue)
{
	return GetPrivateProfileInt(p_section, p_key, p_defaultValue, fileName);
}
float IniHandler::ReadFloat(char* p_section, char* p_key, float p_defaultValue)
{
	char result[255];
	GetPrivateProfileString(p_section, p_key, Utilities::to_string(p_defaultValue).c_str(), result, 255, fileName);
	return (float)atof(result);
}
char* IniHandler::ReadString(char* p_section, char* p_key, char* p_defaultValue)
{
	char* result = new char[255];
	GetPrivateProfileString(p_section, p_key, p_defaultValue, result, 255, fileName);
	return result;
}

void IniHandler::WriteInt(char* p_section, char* p_key, int p_value)
{
	WritePrivateProfileString(p_section, p_key, Utilities::to_string(p_value).c_str(), fileName);
}
void IniHandler::WriteFloat(char* p_section, char* p_key, float p_value)
{
	WritePrivateProfileString(p_section, p_key, Utilities::to_string(p_value).c_str(), fileName);
}
void IniHandler::WriteString(char* p_section, char* p_key, char* p_value)
{
	WritePrivateProfileString(p_section, p_key, p_value, fileName);
}