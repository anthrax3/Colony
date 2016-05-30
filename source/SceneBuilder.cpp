/**
 *   @file: SceneBuilder.cpp
 *
 *   @date: May 30, 2016
 * @author: mateusz
 */

#include "GameObject.h"
#include "GraphicsComponent.h"
#include "Line2DRenderItem.h"
#include "LocalTransformComponent.h"
#include "SceneBuilder.h"

using namespace std;

/**
 * @name    buildCircleFromLines
 * @brief   build a loose circle from line segments
 * @return  scene root
 */
shared_ptr<GameObject> SceneBuilder::buildCircleFromLines() {
    auto root = make_shared<GameObject>();

    auto transform = make_shared<LocalTransformComponent>();
    transform->translate = QVector3D (320, 240, 0);
    root->addComponent(transform);

    for (int i = 0; i < 36; i++) {
        auto node = make_shared<GameObject>();
        auto graphics = make_shared<GraphicsComponent>();
        graphics->render_item = make_shared<Line2DRenderItem>();
        node->addComponent(graphics);

        transform = make_shared<LocalTransformComponent>();
        const float R = 100;
        const float SCALE = 3;
        auto dsin = [] (double degrees) { return sin(degrees * 3.1415 / 180.0); };

        transform->translate = QVector3D (dsin(i * 10) * R, dsin(i * 10 + 90) * R, 0.0);
        transform->rotate = QVector3D(0, 0, -i * 10);
        transform->scale = QVector3D(SCALE, SCALE, 1);
        node->addComponent(transform);

        root->addChild(node);
    }

    return root;
}
