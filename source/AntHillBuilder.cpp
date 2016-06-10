/**
 *   @file: AntHillBuilder.cpp
 *
 *   @date: Jun 6, 2016
 * @author: mateusz
 */

#include "LocalTransformComponent.h"
#include "AntGeneratorComponent.h"
#include "GraphicsComponent.h"
#include "CircleRenderItem.h"
#include "GranaryComponent.h"
#include "AntHillBuilder.h"

using namespace std;

/**
 * @name    buildAntHill
 * @brief   Creates an AntHill at given location
 * @param   x Location
 * @param   y Location
 * @return  The created AntHill that can be added to the Game Scene
 */
shared_ptr<GameObject> AntHillBuilder::buildAntHill(float x, float y) {
    auto transform = make_shared<LocalTransformComponent>();
    transform->translate = QVector3D(x, y, 0);

    auto granary = make_shared<GranaryComponent>();
    granary->food = 450;

    auto ant_generator = make_shared<AntGeneratorComponent>();
    ant_generator->time_interval = 0.5f;
    ant_generator->enabled = true;

    auto visual_representation = buildAntHillVisual();

    auto ant_hill = make_shared<GameObject>();
    ant_hill->addChild(visual_representation);
    ant_hill->addComponent(granary);
    ant_hill->addComponent(ant_generator);
    ant_hill->addComponent(transform);

    return ant_hill;
}

/**
 * @name    buildAntHillVisual
 * @brief   Creates an AntHill visual representation
 * @return  The created visual rep. of Ant Hill that can be added as child to the actual AntHill
 */
shared_ptr<GameObject> AntHillBuilder::buildAntHillVisual() {
    auto transform = make_shared<LocalTransformComponent>();
    transform->scale = QVector3D(10, 10, 0);

    auto graphics = make_shared<GraphicsComponent>();
    graphics->render_item = make_shared<CircleRenderItem>();

    auto root = make_shared<GameObject>();
    root->addComponent(graphics);
    root->addComponent(transform);

    return root;
}
