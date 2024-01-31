/*****************************************************************//**
 * \file   ECS.hpp
 * \brief  
 * 
 * \author Muhammad Syamim
 * \date   21/01/2024
 *********************************************************************/

#pragma once
#include <vector>
#include <array>
#include <bitset>
#include <memory>

class Component;
class Entity;
class Manager;

constexpr std::size_t maxComponents = 32;
constexpr std::size_t maxGroups = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using GroupBitSet = std::bitset<maxGroups>;
using ComponentArray = std::array<Component*, maxComponents>;
using ComponentID = std::size_t;
using Group = std::size_t;

inline ComponentID GetComponentTypeID() {
	static ComponentID lastID = 0;
	return lastID++;
}

template <typename T> inline ComponentID GetComponentTypeID() noexcept {
	static ComponentID typeID = GetComponentTypeID();
	return typeID;
}

class Component {
public:
	Entity* entity;

	virtual void Init() { }
	virtual void Update() { }
	virtual void Draw() { }

	virtual ~Component() { }
};

class Entity {
public:
	Entity(Manager& manager) :manager(manager) {

	}

	void Update() {
		for (auto& c : components) c->Update();
	}
	void Draw() {
		for (auto& c : components) c->Draw();
	}
	void Destroy() {
		isActive = false;
	}
	bool IsActive() const {
		return isActive;
	}
	bool HasGroup(Group group) {
		return groupBitSet[group];
	}
	void AddGroup(Group group);
	void DelGroup(Group group) {
		groupBitSet[group] = false;
	}

	template <typename T> 
	bool HasComponent() const {
		return componentBitSet[GetComponentTypeID<T>()];
	}
	template <typename T, typename... TArgs> 
	T& AddComponent(TArgs&&... mArgs) {
		T* c(new T(std::forward<TArgs>(mArgs)...));
		c->entity = this;
		std::unique_ptr<Component> uniquePtr { c };

		components.emplace_back(std::move(uniquePtr));
		componentArray[GetComponentTypeID<T>()] = c;
		componentBitSet[GetComponentTypeID<T>()] = true;
		
		c->Init();
		return *c;
	}
	template <typename T> 
	T& GetComponent() const {
		auto ptr(componentArray[GetComponentTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}

private:
	bool isActive = true;

	Manager& manager;

	std::vector<std::unique_ptr<Component>> components;

	ComponentArray componentArray;
	ComponentBitSet componentBitSet;
	GroupBitSet groupBitSet;
};

class Manager {
public:
	void Update() {
		for (auto& e : entities) e->Update();
	}
	void Draw() {
		for (auto& e : entities) e->Draw();
	}
	void Refresh() {
		for (auto i(0u); i < maxGroups; i++) {
			auto& v(groupedEntities[i]);
			v.erase(
				std::remove_if(
					std::begin(v),
					std::end(v),
					[i](Entity* entity) {
						return !entity->IsActive() || !entity->HasGroup(i);
					}
				),
				std::end(v)
			);
		}

		entities.erase(std::remove_if(std::begin(entities),std::end(entities),
				[](const std::unique_ptr<Entity>& mEntity) {
					return !mEntity->IsActive(); }),
					std::end(entities));
	}
	void AddToGroup(Entity* entity, Group group) {
		groupedEntities[group].emplace_back(entity);
	}
	std::vector<Entity*>& GetGroup(Group group) {
		return groupedEntities[group];
	}
	Entity& AddEntity() {
		Entity* e = new Entity(*this);
		std::unique_ptr<Entity> unique_ptr { e };
		entities.emplace_back(std::move(unique_ptr));
		return *e;
	}

private:
	std::vector<std::unique_ptr<Entity>> entities;
	std::array<std::vector<Entity*>, maxGroups> groupedEntities;
};