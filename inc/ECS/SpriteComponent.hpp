/*****************************************************************//**
 * \file   SpriteComponent.hpp
 * \brief  
 * 
 * \author Muhammad Syamim
 * \date   22/01/2024
 *********************************************************************/

#pragma once
#include "ECS/ECS.hpp"
#include "SDL.h"

class SpriteComponent : public Component {
public:
	SpriteComponent() = default;
	SpriteComponent(const char* filepath) {
		SetTexture(filepath);
	}

	void Init() override {
		transform = &entity->GetComponent<TransformComponent>();

		srcRect.x = srcRect.y = 0;
		srcRect.w = srcRect.h = 32;

		dstRect.w = dstRect.h = 32;
	}
	void Update() override {
		dstRect.x = (int)transform->position.x;
		dstRect.y = (int)transform->position.y;
	}
	void Draw() override {
		TextureManager::Draw(texture, srcRect, dstRect);
	}

	void SetTexture(const char* filepath) {
		texture = TextureManager::LoadTexture(filepath);
	}

private:
	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect srcRect, dstRect;
};
