/*****************************************************************//**
 * \file   SpriteComponent.hpp
 * \brief  
 * 
 * \author Muhammad Syamim
 * \date   22/01/2024
 *********************************************************************/

#pragma once
#include "ECS/ECS.hpp"
#include "TextureManager.hpp"
#include <SDL.h>

class SpriteComponent : public Component {
public:
	SpriteComponent() = default;
	SpriteComponent(const char* filepath) {
		SetTexture(filepath);
	}

	~SpriteComponent() {
		SDL_DestroyTexture(texture);
	}

	void Init() override {
		transform = &entity->GetComponent<TransformComponent>();

		srcRect.x = srcRect.y = 0;
		srcRect.w = transform->width;
		srcRect.h = transform->height;
	}
	void Update() override {
		dstRect.x = static_cast<int>(transform->position.x);
		dstRect.y = static_cast<int>(transform->position.y);
		dstRect.w = transform->width * transform->scale;
		dstRect.h = transform->height * transform->scale;
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
