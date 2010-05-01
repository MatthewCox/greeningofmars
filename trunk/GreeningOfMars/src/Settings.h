#pragma once

class Settings
{
public:
	static struct View
	{
		static int Width;
		static int Height;
		static double FOV;
		static bool Fullscreen;
	};

	static struct Mouse
	{
		static float MovementRatio;
	};

	static struct Movement
	{
		static float Speed;
	};

	static struct UI
	{
		static char* FontPath;
	};

	static void Load(char* filepath);
	static void Save(char* filepath);
};
