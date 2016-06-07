/**
 *   @file: AntGeneratorComponent.cpp
 *
 *   @date: Jun 6, 2016
 * @author: mateusz
 */

#include "LocalTransformComponent.h"
#include "GranaryComponent.h"
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
    if (const auto &granary = finder->findComponentByType<GranaryComponent>()) {
        if (granary->food >= 10) {
            granary->food -= 10;
            auto ant = make_shared<Ant>();
            owner->bufferedAddChild(ant);
        }
    }
}
