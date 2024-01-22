/*****************************************************************//**
 * \file   TextureManager.cpp
 * \brief  
 * 
 * \author Muhammad Syamim
 * \date   21/01/2024
 *********************************************************************/

#include "TextureManager.hpp"

SDL_Texture* TextureManager::LoadTexture(const char* filename) {
  SDL_Surface* surface = IMG_Load(filename);
  SDL_Texture* texture = SDL_CreateTextureFromSurface(RPG_GAME::Renderer, surface);
  SDL_FreeSurface(surface);
 
  return texture;
}

void TextureManager::Draw(SDL_Texture* texture, SDL_Rect source, SDL_Rect destination) {
  SDL_RenderCopy(RPG_GAME::Renderer, texture, &source, &destination);
}
