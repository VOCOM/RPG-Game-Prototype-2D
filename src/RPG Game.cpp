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
#include "Collision.hpp"

#include <iostream>

// TODO: Abstract
Map* map;
Manager manager;
auto& Player(manager.AddEntity());
auto& Wall(manager.AddEntity());

enum GroupLabels : std::size_t {
	GroupMap,
	GroupPlayer,
	GroupColliders
};

auto& Tile0(manager.AddEntity());
auto& Tile1(manager.AddEntity());
auto& Tile2(manager.AddEntity());

auto& Tiles(manager.GetGroup(GroupMap));
auto& Players(manager.GetGroup(GroupPlayer));

std::vector<ColliderComponent*> RPG_GAME::colliders;
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

	Tile0.AddComponent<TileComponent>(200, 200, 32, 32, 0);
	Tile0.AddComponent<ColliderComponent>("Dirt");
	Tile0.AddGroup(GroupMap);

	Tile1.AddComponent<TileComponent>(250, 250, 32, 32, 1);
	Tile1.AddComponent<ColliderComponent>("Grass");
	Tile1.AddGroup(GroupMap);

	Tile2.AddComponent<TileComponent>(150, 150, 32, 32, 2);
	Tile2.AddGroup(GroupMap);

	Player.AddComponent<TransformComponent>(0, 0);
	Player.AddComponent<SpriteComponent>("assets/Player.bmp");
	Player.AddComponent<KeyboardController>();
	Player.AddComponent<ColliderComponent>("Player");
	Player.AddGroup(GroupPlayer);

	Wall.AddComponent<TransformComponent>(500.0f, 100.0f, 20, 300, 1);
	Wall.AddComponent<SpriteComponent>("assets/water.png");
	Wall.AddComponent<ColliderComponent>("Wall");
	Wall.AddGroup(GroupMap);

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
	manager.Update();

	for (auto cc : colliders) {
		Collision::AABB(Player.GetComponent<ColliderComponent>(), *cc);
	}
}

void RPG_GAME::Render() {
	SDL_RenderClear(Renderer);

	// Render sequence
	for (auto& t : Tiles)		t->Draw();
	for (auto& p : Players) p->Draw();

	SDL_RenderPresent(Renderer);
}

void RPG_GAME::Clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(Renderer);
	SDL_Quit();
}
