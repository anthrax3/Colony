/**
 *   @file: GameObject.cpp
 *
 *   @date: May 17, 2016
 * @author: Mateusz Midor
 */

#include <typeinfo>
#include "GameObject.h"

using namespace std;

GameObject::GameObject() {
}

GameObject::~GameObject() {
}

/**
 * @name	addComponent
 * @brief	Add new component to the GameObject
 * @param	component Component to be added
 * @note	The component type must be unique within GameObject
 */
void GameObject::addComponent(const std::shared_ptr<Component> &component) {
	component->finder = this;
	unsigned long long hash = typeid(*component).hash_code();
    components.emplace(hash, component);
}

/**
 * @name		findComponentByHashCode
 * @implements	ComponentFinder::findComponentByHashCode
 */
shared_ptr<Component> GameObject::findComponentByHashCode(unsigned long long hash) {
	auto result = components.find(hash);

	// component found. Return pointer
	if (result != components.end())
		return result->second;

	// component not found. Return empty pointer
	return std::shared_ptr<Component>();
}
