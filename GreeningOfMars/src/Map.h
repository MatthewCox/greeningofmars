#pragma once

#include "DrawableObject.h"

#include <vector>

class Map : public DrawableObject
{
private:
	std::vector<int> m_map;
	int m_width;
	int m_height;

public:
	Map(void);
	~Map(void);

	void Draw(void);
	bool Load(char p_filepath[]);

	int Tile(int p_X, int p_Y);
	void SetDrawColour(int p_X, int p_Y);
};