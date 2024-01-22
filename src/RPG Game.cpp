/*****************************************************************//**
 * \file   RPG Game Prototype.cpp
 * \brief  
 * 
 * \author Muhammad Syamim
 * \date   21/01/2024
 *********************************************************************/

#include "RPG Game.hpp"
#include "TextureManager.hpp"
#include "Map.hpp"
#include "ECS/Components.hpp"

#include <iostream>

// TODO: Abstract
Map* map;
Manager manager;
auto& Player(manager.AddEntity());

SDL_Renderer* RPG_GAME::Renderer = nullptr;
SDL_Event RPG_GAME::event;

RPG_GAME::RPG_GAME() : isRunning(false), window(nullptr) {
	/* Empty by Design */
}

RPG_GAME::~RPG_GAME() {
	/* Empty by Design */
}

void RPG_GAME::Init(const char* title, int xPos, int yPos, int width, int height, bool isFullscreen) {
	int fullscreenFlag = 0;
	if (isFullscreen) fullscreenFlag = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) return;

	window = SDL_CreateWindow(title, xPos, yPos, width, height, fullscreenFlag);
	if (!window) {
		std::cout << "Failed to create Window!!!" << std::endl;
		return;
	}

	Renderer = SDL_CreateRenderer(window, -1, 0);
	if (!Renderer) {
		std::cout << "Failed to create Renderer!!!" << std::endl;
		return;
	}
	SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);

	isRunning = true;

	// TODO: Abstract
	map = new Map();
	Player.AddComponent<TransformComponent>(0, 0);
	Player.AddComponent<SpriteComponent>("assets/Player.bmp");
	Player.AddComponent<KeyboardController>();

}

void RPG_GAME::HandleEvents() {
	SDL_PollEvent(&event);

	switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
	}
}

void RPG_GAME::Update() {
	// TODO:
	manager.Update();

	std::cout << Player.GetComponent<TransformComponent>().position.x << ","
		<< Player.GetComponent<TransformComponent>().position.y << std::endl;
}

void RPG_GAME::Render() {
	SDL_RenderClear(Renderer);

	// TODO:
	map->DrawMap();
	manager.Draw();

	SDL_RenderPresent(Renderer);
}

void RPG_GAME::Clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(Renderer);
	SDL_Quit();
}
