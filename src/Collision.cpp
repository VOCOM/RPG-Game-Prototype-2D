#include "Collision.hpp"
#include "ECS/ColliderComponent.hpp"
#include <iostream>

bool Collision::AABB(const SDL_Rect& rectA, const SDL_Rect& rectB) {
  if (
    rectA.x + rectA.w >= rectB.x &&
    rectB.x + rectB.w >= rectA.x &&
    rectA.y + rectA.h >= rectB.y &&
    rectB.y + rectB.h >= rectA.y)
    return true;
  return false;
}

bool Collision::AABB(const ColliderComponent& colA, const ColliderComponent& colB) {
  // Self Collision Guard
  if (colA.tag == colB.tag) return false;

  // No Collision Guard
  if (!AABB(colA.collider, colB.collider)) return false;
    
  std::cout << colA.tag << " hit: " << colB.tag << "\n";
  return true;
}
