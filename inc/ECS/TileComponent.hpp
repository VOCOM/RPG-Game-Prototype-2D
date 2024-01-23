/*****************************************************************//**
 * \file   TileComponent.hpp
 * \brief  
 * 
 * \author Muhammad Syamim
 * \date   23/01/2024
 *********************************************************************/

#pragma once
#include "ECS.hpp"
#include "Components.hpp"
#include <SDL.h>

class TileComponent : public Component {
public:
	TransformComponent* transform;
	SpriteComponent* sprite;

	SDL_Rect tileRect;
	int tileID;
	const char* filepath;

	TileComponent() = default;

	TileComponent(int x, int y, int w, int h, int id) {
		tileRect.x = x;
		tileRect.y = y;
		tileRect.w = w;
		tileRect.h = h;
		tileID = id;

		switch (tileID) {
			case 0:
				filepath = "assets/dirt.png";
				break;
			case 1:
				filepath = "assets/grass.png";
				break;
			case 2:
				filepath = "assets/water.png";
				break;
			default:
				break;
		}
	}

	void Init() override {
		entity->AddComponent<TransformComponent>(tileRect.x, tileRect.y, tileRect.w, tileRect.h, 1);
		transform = &entity->GetComponent<TransformComponent>();

		entity->AddComponent<SpriteComponent>(filepath);
		sprite = &entity->GetComponent<SpriteComponent>();
	}
};
