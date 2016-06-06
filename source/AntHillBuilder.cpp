/**
 *   @file: AntHillBuilder.cpp
 *
 *   @date: Jun 6, 2016
 * @author: mateusz
 */

#include "LocalTransformComponent.h"
#include "AntGeneratorComponent.h"
#include "AntHillBuilder.h"

using namespace std;

/**
 * @name    buildAntHill
 * @brief   Creates an AntHill at given location
 * @param   x Location
 * @param   y Location
 * @return  The created AntHill that can be added to the Game Scene
 */
std::shared_ptr<GameObject> AntHillBuilder::buildAntHill(float x, float y) {

    auto transform = make_shared<LocalTransformComponent>();
    transform->translate = QVector3D(x, y, 0);

    auto ant_generator = make_shared<AntGeneratorComponent>();
    ant_generator->time_interval = 0.1f;
    ant_generator->enabled = true;

    auto ant_hill = make_shared<GameObject>();
    ant_hill->addComponent(ant_generator);
    ant_hill->addComponent(transform);
    return ant_hill;
}
