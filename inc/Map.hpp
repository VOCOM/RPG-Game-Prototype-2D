/*****************************************************************//**
 * \file   Map.hpp
 * \brief  
 * 
 * \author Muhammad Syamim
 * \date   21/01/2024
 *********************************************************************/

#pragma once
#include "RPG Game.hpp"
#include <vector>

class Map {
public:
	typedef std::vector<std::vector<int>> BITMAP;
	struct Size {
		int Height;
		int Width;
	};

	Map();
	~Map();

	void LoadMap(BITMAP);
	void DrawMap();

private:
	SDL_Rect source, destination;
	BITMAP bitMap;

	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;
};
