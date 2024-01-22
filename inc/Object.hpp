/*****************************************************************//**
 * \file   Entity.hpp
 * \brief  
 * 
 * \author Muhammad Syamim
 * \date   21/01/2024
 *********************************************************************/

#pragma once
#include "RPG Game.hpp"

class Object {
public:
	struct Position {
		int x, y;
	};
	
	Object(const char*, Position);
	~Object();

	void Update();
	void Render();

private:
	Position position;
	SDL_Texture* texture;
	SDL_Rect srcRectangle, dstRectangle;
};
