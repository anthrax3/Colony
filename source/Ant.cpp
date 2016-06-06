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
#include "SimpleAntDriver.h"
#include "Ant.h"

using namespace std;

/**
 * @brief   Constructor. Here we build an ant from components
 */
Ant::Ant() {
    // look
    auto graphics = make_shared<GraphicsComponent>();
    graphics->render_item = make_shared<Line2DRenderItem>();
    addComponent(graphics);

    // position
    auto transform = make_shared<LocalTransformComponent>();
    transform->translate = QVector3D(0, 0, 0);
    transform->scale = QVector3D(4, 4, 1);
    addComponent(transform);

    // mind
    auto driver = make_shared<SimpleAntDriver>();
    addComponent(driver);
}

Ant::~Ant() {
}

