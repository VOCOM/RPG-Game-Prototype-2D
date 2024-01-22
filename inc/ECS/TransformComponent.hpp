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
	TransformComponent() :position(0,0) {

	}
	TransformComponent(int x, int y) :position(x,y) {
		
	}
	
	void Init() override {
		velocity.x = 0;
		velocity.y = 0;
	}
	void Update() override {
		position.x += velocity.x * speed; // ???
		position.y += velocity.y * speed;
	}

	Vector2D position;
	Vector2D velocity;

	int speed = 3;

};
