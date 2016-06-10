/**
 *   @file: Ant.cpp
 *
 *   @date: Jun 5, 2016
 * @author: mateusz
 */

#include <memory>
#include "GraphicsComponent.h"
#include "Line2DRenderItem.h"
#include "LocalTransformComponent.h"
#include "PhysicsComponent.h"
#include "CircleColliderItem.h"
#include "SimpleAntDriver.h"
#include "Ant.h"

using namespace std;

/**
 * @brief   Constructor. Here we build an ant from components
 */
Ant::Ant() {
    const float RADIUS = 4.0f;

    // look
    auto graphics = make_shared<GraphicsComponent>();
    graphics->render_item = make_shared<Line2DRenderItem>();
    addComponent(graphics);

    // position
    auto transform = make_shared<LocalTransformComponent>();
    transform->translate = QVector3D(0, 0, 0);
    transform->scale = QVector3D(RADIUS, RADIUS, 1);
    addComponent(transform);

    // physics
    auto physics = make_shared<PhysicsComponent>();
    physics->collider_item = make_shared<CircleColliderItem>(RADIUS);
    addComponent(physics);

    // mind
    auto driver = make_shared<SimpleAntDriver>();
    addComponent(driver);
}

Ant::~Ant() {
}

