/*****************************************************************//**
 * \file   main.cpp
 * \brief  
 * 
 * \author Muhammad Syamim
 * \date   21/01/2024
 *********************************************************************/

#include "RPG Game.hpp"
#include "FrameLimiter.hpp"

const char const* Title = "RPG Prototype";
const struct {
	int width = 1280;
	int height = 800;
	bool isFullscreen = false;
} StartupSize;
RPG_GAME* gameInstance = nullptr;

int main(int argc, char** argv) {
	gameInstance = new RPG_GAME();

	gameInstance->Init(Title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
										 StartupSize.width, StartupSize.height, StartupSize.isFullscreen);

	while (gameInstance->Running()) {
		FrameLimiter FPSLimiter;

		// Game Loop
		gameInstance->HandleEvents();
		gameInstance->Update();
		gameInstance->Render();
	}

	gameInstance->Clean();

	return 0;
}
