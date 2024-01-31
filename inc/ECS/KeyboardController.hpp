/*****************************************************************//**
 * \file   KeyboardController.hpp
 * \brief  
 * 
 * \author Muhammad Syamim
 * \date   22/01/2024
 *********************************************************************/

#pragma once
#include "../RPG Game.hpp"
#include "ECS.hpp"
#include "Components.hpp"

class KeyboardController : public Component {
public:
	TransformComponent* transform;

	void Init() override {
		transform = &entity->GetComponent<TransformComponent>();
	}
	void Update() override {
		if (RPG_GAME::event.type == SDL_KEYDOWN) {
			switch (RPG_GAME::event.key.keysym.sym) {
				case SDLK_w:
				case SDLK_UP:
					transform->velocity.y = -1;
					break;
				case SDLK_a:
				case SDLK_LEFT:
					transform->velocity.x = -1;
					break;
				case SDLK_s:
				case SDLK_DOWN:
					transform->velocity.y = 1;
					break;
				case SDLK_d:
				case SDLK_RIGHT:
					transform->velocity.x = 1;
					break;
				default:
					break;
			}
		}

		if (RPG_GAME::event.type == SDL_KEYUP) {
			switch (RPG_GAME::event.key.keysym.sym) {
				case SDLK_w:
				case SDLK_UP:
					transform->velocity.y = 0;
					break;
				case SDLK_a:
				case SDLK_LEFT:
					transform->velocity.x = 0;
					break;
				case SDLK_s:
				case SDLK_DOWN:
					transform->velocity.y = 0;
					break;
				case SDLK_d:
				case SDLK_RIGHT:
					transform->velocity.x = 0;
					break;
				default:
					break;
			}
		}
	}
};
