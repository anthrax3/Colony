/**
 *   @file: RotatorComponent.cpp
 *
 *   @date: May 30, 2016
 * @author: mateusz
 */

#include "RotatorComponent.h"

RotatorComponent::RotatorComponent() {
}

RotatorComponent::~RotatorComponent() {
}

/**
 * @name    update
 * @brief   rotates the LocalTransformComponeng by given angles
 * @param   dt Delta time in seconds
 */
void RotatorComponent::update(float dt) {
    if (!transform)
        transform = findComponentByType<LocalTransformComponent>();

    if (transform)
        transform->rotate += rotate * dt;
}
