/**
 *   @file: PhysicsComponent.cpp
 *
 *   @date: Jun 10, 2016
 * @author: mateusz
 */

#include <iostream>
#include "LocalTransformComponent.h"
#include "CollisionResolver.h"
#include "PhysicsComponent.h"


std::shared_ptr<CollisionResolver> resolver;

PhysicsComponent::PhysicsComponent() {
    collider_registered = false;
}

/**
 * @brief   Destructor. Unregister the collider if possible
 */
PhysicsComponent::~PhysicsComponent() {
    if ((collider_registered) && (collider_item) && (resolver)) {
        resolver->removeCollider(this);
        collider_registered = false;
        std::cout << "PhysicsComponent: collider unregistered!" << std::endl;
    }
}

/**
 * @name    update
 * @brief   Register the collider in CollisionResolver scene node, if possible
 * @param   delta_time Time elapsed from last update in seconds
 */
void PhysicsComponent::update(float delta_time) {
    if ((!collider_registered) && (collider_item)) {
        resolver = owner->findNodeByTypeEverywhere<CollisionResolver>();
        if (resolver) {
            resolver->addCollider(this);
            collider_registered = true;
            std::cout << "PhysicsComponent: collider registered!" << std::endl;
        }
    }

    if (collider_item)
        if (auto transform = findComponentByType<LocalTransformComponent>())
            collider_item->updateCollisionMesh(transform->absolute_transform);
}
