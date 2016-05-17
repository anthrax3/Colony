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
    // nothing to do here
}

GameObject::~GameObject() {
    // nothing to do here
}

void GameObject::addComponent(const std::shared_ptr<Component> &component) {
    auto hash = typeid(*component).hash_code();
    components.emplace(hash, component);
}
