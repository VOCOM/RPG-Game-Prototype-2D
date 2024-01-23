/*****************************************************************//**
 * \file   PositionComponent.hpp
 * \brief  
 * 
 * \author Muhammad Syamim
 * \date   22/01/2024
 *********************************************************************/

#pragma once
#include "ECS.hpp"
#include "../Vector2D.hpp"

struct TransformComponent : public Component {
	TransformComponent() {

	}
	TransformComponent(float x, float y) :position(x,y) {
		
	}
	TransformComponent(float x, float y, int w, int h, int sc) :
		position(x, y), width(w), height(h), scale(sc) {

	}
	
	void Init() override {

	}
	void Update() override {
		position.x += velocity.x * speed; // ???
		position.y += velocity.y * speed;
	}

	Vector2D position;
	Vector2D velocity;

	int height = 32;
	int width = 32;
	int scale = 1;

	int speed = 3;
};
