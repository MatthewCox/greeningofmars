#include "Map.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <windows.h>
#include <GL/GL.h>

#include "Utilities.h"

Map::Map(void)
{
	m_width = 0;
	m_height = 0;
	m_map.empty();
}

Map::~Map(void)
{
}

void Map::Draw()
{
	for (int j = 0; j < m_height - 1; j++)
	{
		glBegin(GL_TRIANGLE_STRIP);
		for (int i = 0; i < m_width - 1; i++)
		{
			glColor3f(1.0f/(float)Tile(i, j), 1.0f/(float)Tile(i, j), 1.0f/(float)Tile(i, j));
			switch (Tile(i,j))
			{
			case 0:
				glColor3f(0,0,1);
				break;
			case 1:
				glColor3f(0,0.8f,0);
				break;
			case 2:
				glColor3f(0,0.5f,0);
				break;
			}
			glVertex3d(i, Tile(i,j), j);
			glColor3f(1.0f/(float)Tile(i, j+1), 1.0f/(float)Tile(i, j+1), 1.0f/(float)Tile(i, j+1));
			switch (Tile(i,j+1))
			{
			case 0:
				glColor3f(0,0,1);
				break;
			case 1:
				glColor3f(0,0.8f,0);
				break;
			case 2:
				glColor3f(0,0.5f,0);
				break;
			}
			glVertex3d(i, Tile(i, j+1), j+1);
			glColor3f(1.0f/(float)Tile(i+1, j), 1.0f/(float)Tile(i+1, j), 1.0f/(float)Tile(i+1, j));
			switch (Tile(i+1,j))
			{
			case 0:
				glColor3f(0,0,1);
				break;
			case 1:
				glColor3f(0,0.8f,0);
				break;
			case 2:
				glColor3f(0,0.5f,0);
				break;
			}
			glVertex3d(i+1, Tile(i+1, j), j);
			glColor3f(1.0f/(float)Tile(i+1, j+1), 1.0f/(float)Tile(i+1, j+1), 1.0f/(float)Tile(i+1, j+1));
			switch (Tile(i+1,j+1))
			{
			case 0:
				glColor3f(0,0,1);
				break;
			case 1:
				glColor3f(0,0.8f,0);
				break;
			case 2:
				glColor3f(0,0.5f,0);
				break;
			}
			glVertex3d(i+1, Tile(i+1, j+1), j+1);
		}
		glEnd();
	}
}

bool Map::Load(char p_filepath[])
{
	std::string line, bit;
	std::ifstream fin;
	fin.open(p_filepath);
	if (fin.is_open())
	{
		std::string temp_s;
		std::vector<std::string> temp_v;

		int tile_id;

		while (fin >> temp_s)
		{
			m_height++;
			temp_v = Utilities::Split(temp_s.c_str(), ',');
			for (int i = 0; i < (int)temp_v.size(); i++)
			{
				tile_id = atoi(temp_v[i].c_str());
				m_map.push_back(tile_id);
			}
			if ((int)temp_v.size() > m_width)
			{
				m_width = temp_v.size();
			}
		}

		fin.close();

		if (m_map.size() != m_width * m_height)
		{
			m_map.clear();
			m_width = 0;
			m_height = 0;
			throw "Size mis-match; possible map file corruption";
		}
	}
	else
	{
		throw "Couldn't open map file; possible permissions issue or file does not exist";
	}
	return true;
}

int Map::Tile(int p_X, int p_Y)
{
	return m_map[p_X+(p_Y*m_width)];
}