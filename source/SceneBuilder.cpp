/**
 *   @file: SceneBuilder.cpp
 *
 *   @date: May 30, 2016
 * @author: mateusz
 */

#include "GameObject.h"
#include "GraphicsComponent.h"
#include "Line2DRenderItem.h"
#include "CircleRenderItem.h"
#include "LocalTransformComponent.h"
#include "RotatorComponent.h"
#include "Ant.h"
#include "AntHillBuilder.h"
#include "CollisionResolver.h"
#include "CircleColliderItem.h"
#include "BoxColliderItem.h"
#include "SceneBuilder.h"

using namespace std;

/**
 * @name    buildCircleFromLines
 * @brief   build a loose circle from line segments
 * @return  scene root
 */
shared_ptr<GameObject> SceneBuilder::buildCircleFromLines() {
    auto root = make_shared<GameObject>();

    // center the circle about (320, 240)
    auto transform = make_shared<LocalTransformComponent>();
    transform->translate = QVector3D(320, 240, 0);
    root->addComponent(transform);

    // make the circle rotate 15 degrees/sec
    auto rotator = make_shared<RotatorComponent>();
    rotator->rotate = QVector3D(0, 0, 15);
    root->addComponent(rotator);

    // add segments as children nodes
    for (int i = 0; i < 36; i++) {
        auto node = make_shared<GameObject>();
        auto graphics = make_shared<GraphicsComponent>();
        graphics->render_item = make_shared<Line2DRenderItem>();
        node->addComponent(graphics);

        transform = make_shared<LocalTransformComponent>();
        const float R = 100;
        const float SCALE = 3;
        auto dsin = [] (double degrees) {return sin(degrees * 3.1415 / 180.0);};

        transform->translate = QVector3D(dsin(i * 10) * R, dsin(i * 10 + 90) * R, 0.0);
        transform->rotate = QVector3D(0, 0, -i * 10);
        transform->scale = QVector3D(SCALE, SCALE, 1);
        node->addComponent(transform);

        root->addChild(node);
    }

    return root;
}

/**
 * @name    buildDoubleCircleFromLines
 * @brief   build a loose circle inside circle from line segments
 * @return  scene root
 */
shared_ptr<GameObject> SceneBuilder::buildDoubleCircleFromLines() {
    auto root = make_shared<GameObject>();

    // center the circle about (320, 240)
    auto transform = make_shared<LocalTransformComponent>();
    transform->translate = QVector3D(320, 240, 0);
    root->addComponent(transform);

    auto right = make_shared<GameObject>();
    auto rtransform = make_shared<LocalTransformComponent>();
    right->addComponent(rtransform);

    // make the circle rotate 15 degrees/sec
    auto rrotator = make_shared<RotatorComponent>();
    rrotator->rotate = QVector3D(0, 0, 15);
    right->addComponent(rrotator);

    // add segments as children nodes
    for (int i = 0; i < 36; i++) {
        auto node = make_shared<GameObject>();
        auto graphics = make_shared<GraphicsComponent>();
        graphics->render_item = make_shared<Line2DRenderItem>();
        node->addComponent(graphics);

        transform = make_shared<LocalTransformComponent>();
        const float R = 100;
        const float SCALE = 3;
        auto dsin = [] (double degrees) {return sin(degrees * 3.1415 / 180.0);};

        transform->translate = QVector3D(dsin(i * 10) * R, dsin(i * 10 + 90) * R, 0.0);
        transform->rotate = QVector3D(0, 0, -i * 10);
        transform->scale = QVector3D(SCALE, SCALE, 1);
        node->addComponent(transform);

        right->addChild(node);
    }

    auto left = make_shared<GameObject>();
    auto ltransform = make_shared<LocalTransformComponent>();
    left->addComponent(ltransform);

    // make the circle rotate 15 degrees/sec
    auto lrotator = make_shared<RotatorComponent>();
    lrotator->rotate = QVector3D(0, 0, -15);
    left->addComponent(lrotator);

    // add segments as children nodes
    for (int i = 0; i < 36; i++) {
        auto node = make_shared<GameObject>();
        auto graphics = make_shared<GraphicsComponent>();
        graphics->render_item = make_shared<Line2DRenderItem>();
        node->addComponent(graphics);

        transform = make_shared<LocalTransformComponent>();
        const float R = 110;
        const float SCALE = 3;
        auto dsin = [] (double degrees) {return sin(degrees * 3.1415 / 180.0);};

        transform->translate = QVector3D(dsin(i * 10) * R, dsin(i * 10 + 90) * R, 0.0);
        transform->rotate = QVector3D(0, 0, -i * 10);
        transform->scale = QVector3D(SCALE, SCALE, 1);
        node->addComponent(transform);

        left->addChild(node);
    }

    root->addChild(right);
    root->addChild(left);
    return root;
}

/**
 * @name    buildSingleAnt
 * @brief   build a scene made from single ant
 * @return  scene root
 */
shared_ptr<GameObject> SceneBuilder::buildSingleAnt() {
    auto ant = make_shared<Ant>();
    return ant;
}

/**
 * @name    buildNumerousAnts
 * @brief   build a scene swarming with ants
 * @return  scene root
 */
shared_ptr<GameObject> SceneBuilder::buildNumerousAnts() {
    auto root = make_shared<GameObject>();
    for (int i = 0; i < 50; i++) {
        auto ant = make_shared<Ant>();
        root->addChild(ant);
    }
    return root;
}

shared_ptr<GameObject> SceneBuilder::buildAntHill(float x, float y) {
    return AntHillBuilder::buildAntHill(x, y);
}

shared_ptr<GameObject> SceneBuilder::buildCirce() {
    auto root = make_shared<GameObject>();

    // center the circle about (320, 240)
    auto transform = make_shared<LocalTransformComponent>();
    transform->translate = QVector3D(320, 240, 0);

    // radius 100
    transform->scale = QVector3D(100, 100, 1);


    auto graphics = make_shared<GraphicsComponent>();
    graphics->render_item = make_shared<CircleRenderItem>();

    root->addComponent(transform);
    root->addComponent(graphics);

    return root;
}

shared_ptr<GameObject> buildCircularObstacle(float x, float y, float radius) {
    auto root = make_shared<GameObject>();

    auto transform = make_shared<LocalTransformComponent>();
    transform->translate = QVector3D(x, y, 0);
    transform->scale = QVector3D(radius, radius, 1);

    auto physics = make_shared<PhysicsComponent>();
    physics->collider_item = make_shared<CircleColliderItem>(radius);

    auto graphics = make_shared<GraphicsComponent>();
    graphics->render_item = make_shared<CircleRenderItem>();

    root->addComponent(transform);
    root->addComponent(physics);
    root->addComponent(graphics);

    return root;
}

shared_ptr<GameObject> buildGameAreaBoundingBox(float width, float height) {
    auto root = make_shared<GameObject>();

    auto transform = make_shared<LocalTransformComponent>();

    auto box_collider = make_shared<BoxColliderItem>(QVector3D(0, 0, 0), width, height, 1.0f);
    box_collider->is_inverted = true;

    auto physics = make_shared<PhysicsComponent>();
    physics->collider_item = box_collider;

    root->addComponent(transform);
    root->addComponent(physics);

    return root;
}

shared_ptr<GameObject> SceneBuilder::buildAntHillSceneWithCollisionResolver(float x, float y) {
    auto root = make_shared<GameObject>();
    auto collision_resolver = make_shared<CollisionResolver>();
    auto ant_hill = AntHillBuilder::buildAntHill(x, y);
    root->addChild(collision_resolver);
    root->addChild(ant_hill);
    root->addChild(buildCircularObstacle(270, 100, 40));
    root->addChild(buildCircularObstacle(200, 200, 35));
    root->addChild(buildCircularObstacle(20, 150, 30));
    root->addChild(buildGameAreaBoundingBox(300, 200));

    return root;
}
