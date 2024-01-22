/*****************************************************************//**
 * \file   TextureManager.hpp
 * \brief  
 * 
 * \author Muhammad Syamim
 * \date   21/01/2024
 *********************************************************************/

#pragma once
#include "RPG Game.hpp"

class TextureManager {
public:
	static SDL_Texture* LoadTexture(const char* filename);
	static void Draw(SDL_Texture*, SDL_Rect, SDL_Rect);
};
