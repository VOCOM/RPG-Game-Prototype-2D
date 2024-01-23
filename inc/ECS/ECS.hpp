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

constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;
using ComponentID = std::size_t;

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

	std::vector<std::unique_ptr<Component>> components;

	ComponentArray componentArray;
	ComponentBitSet componentBitSet;
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
		entities.erase(
			std::remove_if(
				std::begin(entities),
				std::end(entities),
				[](const std::unique_ptr<Entity>& mEntity) {
					return !mEntity->IsActive(); }),
					std::end(entities));

	}
	Entity& AddEntity() {
		Entity* e = new Entity();
		std::unique_ptr<Entity> unique_ptr { e };
		entities.emplace_back(std::move(unique_ptr));
		return *e;
	}

private:
	std::vector<std::unique_ptr<Entity>> entities;
};