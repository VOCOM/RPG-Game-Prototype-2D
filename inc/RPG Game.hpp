/*****************************************************************//**
 * \file   RPG Game.hpp
 * \brief  
 * 
 * \author Muhammad Syamim
 * \date   21/01/2024
 *********************************************************************/

#pragma once
#include <SDL.h>
#include <SDL_image.h>

class RPG_GAME {
public:
	static SDL_Renderer* Renderer;
	static SDL_Event event;

	RPG_GAME();
	~RPG_GAME();

	void Init(const char* title, int xPos, int yPos,
		int width, int height, bool isFullscreen);

	void HandleEvents();
	void Update();
	void Render();
	void Clean();

	bool Running() const { return isRunning; }

private:
	bool isRunning;
	SDL_Window* window;
};