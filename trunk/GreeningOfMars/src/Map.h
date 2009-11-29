#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <windows.h>
#include <GL/GL.h>

#include "DrawableObject.h"
#include "Utilities.h"

using namespace std;

class Map : DrawableObject
{
private:
	vector<int> m_map;
	int m_width;
	int m_height;

public:
	Map(void);
	~Map(void);

	void Draw(void);
	bool Load(char p_filepath[]);

	int Tile(int p_X, int p_Y);
};