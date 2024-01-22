/*****************************************************************//**
 * \file   Entity.cpp
 * \brief  
 * 
 * \author Muhammad Syamim
 * \date   21/01/2024
 *********************************************************************/

#include "Object.hpp"
#include "TextureManager.hpp"

Object::Object(const char* textureSheet, Position initialPosition) :
	position(initialPosition), srcRectangle(), dstRectangle() {
	texture = TextureManager::LoadTexture(textureSheet);
}

Object::~Object() {
}

void Object::Update() {
	//position.x++;
	//position.y++;

	srcRectangle.h = srcRectangle.w = 32;
	srcRectangle.x = srcRectangle.y = 0;

	dstRectangle.x = position.x;
	dstRectangle.y = position.y;
	dstRectangle.h = srcRectangle.h;
	dstRectangle.w = srcRectangle.w;
}

void Object::Render() {
	SDL_RenderCopy(RPG_GAME::Renderer, texture, &srcRectangle, &dstRectangle);
}
