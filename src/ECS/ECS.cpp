#include "../inc/ECS/ECS.hpp"

void Entity::AddGroup(Group group) {
	groupBitSet[group] = true;
	manager.AddToGroup(this, group);
}
