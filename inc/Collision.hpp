/*****************************************************************//**
 * \file   Collision.hpp
 * \brief  
 * 
 * \author Muhammad Syamim
 * \date   23/01/2024
 *********************************************************************/

#pragma once
#include <SDL.h>

class Collision {
public:
	static bool AABB(const SDL_Rect&, const SDL_Rect&);
};
