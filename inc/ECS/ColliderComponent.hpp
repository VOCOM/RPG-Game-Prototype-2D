/*****************************************************************//**
 * \file   ColliderComponent.hpp
 * \brief  
 * 
 * \author Muhammad Syamim
 * \date   23/01/2024
 *********************************************************************/

#pragma once
#include <string>
#include <SDL.h>
#include "Components.hpp"

class ColliderComponent : public Component {
public:
	std::string tag;
	SDL_Rect collider;

	TransformComponent* transform;

	ColliderComponent(std::string t) :tag(t) {

	}

	void Init() override {
		if (!entity->HasComponent<TransformComponent>())
			entity->AddComponent<TransformComponent>();
		transform = &entity->GetComponent<TransformComponent>();
		RPG_GAME::colliders.push_back(this);
	}
	void Update() override {
		collider.x = static_cast<int>(transform->position.x);
		collider.y = static_cast<int>(transform->position.y);
		collider.w = static_cast<int>(transform->width * transform->scale);
		collider.h = static_cast<int>(transform->height * transform->scale);
	}

};
