#pragma once

class IniHandler
{
public:
	static void SetFileName(char* p_fileName);

	static int ReadInt(char* p_section, char* p_key, int p_defaultValue);
	static float ReadFloat(char* p_section, char* p_key, float p_defaultValue);
	static char* ReadString(char* p_section, char* p_key, char* p_defaultValue);

	static void WriteInt(char* p_section, char* p_key, int p_value);
	static void WriteFloat(char* p_section, char* p_key, float p_value);
	static void WriteString(char* p_section, char* p_key, char* p_value);

private:
	static char* fileName;
};
