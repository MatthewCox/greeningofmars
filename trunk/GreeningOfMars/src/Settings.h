#pragma once

class Settings
{
public:
	Settings(void);
	~Settings(void);

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
};
