/**
 *   @file: AntGeneratorComponent.cpp
 *
 *   @date: Jun 6, 2016
 * @author: mateusz
 */

#include "LocalTransformComponent.h"
#include "AntGeneratorComponent.h"

using namespace std;

AntGeneratorComponent::AntGeneratorComponent() {
}

AntGeneratorComponent::~AntGeneratorComponent() {
}

/**
 * @name    fire
 * @brief   Overrides TimerComponent::fire()
 *          Adds one Ant to the GameObject
 */
void AntGeneratorComponent::fire() {
    if (owner->children.size() > 10000)
        return;

    auto ant = make_shared<Ant>();
    owner->bufferedAddChild(ant);
}
