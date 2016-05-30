/**
 *   @file: TransformMatrixCombiner_Test.cpp
 *
 *   @date: May 24, 2016
 * @author: Mateusz Midor
 */

#include <memory>
#include <iostream>
#include <algorithm>
#include <QtGui/QVector3D>
#include <QtGui/QMatrix4x4>
#include "gtest/gtest.h"
#include "GameObject.h"
#include "GraphicsComponent.h"
#include "TransformMatrixCombiner.h"
#include "../source/LocalTransformComponent.h"

using namespace std;

bool matricesEqual(float *m1, float *m2) {
    return equal(m1, m1 + 16, m2);
}

TEST(TransformMatrixCombiner_Test, one_node_graph)
{
    QVector3D rotate(45.0f, 0.0f, 0.0f);
    QMatrix4x4 expected_absolute;
    expected_absolute.rotate(rotate.x(), 1.0f, 0.0f, 0.0f);

    // root node itself
    auto root_node = make_shared<GameObject>();

    // root transform
    auto root_transform = make_shared<LocalTransformComponent>();
    root_transform->rotate = rotate;
    root_node->addComponent(root_transform);

    // root graphics; it holds absolute transform
    auto root_graphics = make_shared<GraphicsComponent>();
    root_node->addComponent(root_graphics);

    // calculate absolute transform from local transform
    TransformMatrixCombiner::combineLocalTransforms(root_node);

    ASSERT_EQ(expected_absolute, *root_graphics->absolute_transform);
}

TEST(TransformMatrixCombiner_Test, combine_transforms_correct)
{
    QVector3D rotate(45.0f, 0.0f, 0.0f);
    QVector3D translate(0.0f, 0.0f, -10.0f);
    QVector3D scale(2.0f, 2.0f, 2.0f);

    QMatrix4x4 rotate_m;
    rotate_m.rotate(rotate.x(), 1.0f, 0.0f, 0.0f);

    QMatrix4x4 translate_m;
    translate_m.translate(translate);

    QMatrix4x4 scale_m;
    scale_m.scale(scale);

    QMatrix4x4 expected_absolute (translate_m * rotate_m * scale_m);

    shared_ptr<GameObject> root_node = make_shared<GameObject>();
    shared_ptr<GameObject> a_node = make_shared<GameObject>();
    root_node->addChild(a_node);
    shared_ptr<GameObject> b_node = make_shared<GameObject>();
    a_node->addChild(b_node);

    // root transform
    shared_ptr<LocalTransformComponent> root_transform = make_shared<LocalTransformComponent>();
    root_transform->translate = translate;
    root_node->addComponent(root_transform);

    // a transform
    shared_ptr<LocalTransformComponent> a_transform = make_shared<LocalTransformComponent>();
    a_transform->rotate = rotate;
    a_node->addComponent(a_transform);

    // b transform
    shared_ptr<LocalTransformComponent> b_transform = make_shared<LocalTransformComponent>();
    b_transform->scale = scale;
    b_node->addComponent(b_transform);

    // b graphics to store absolute transform
    shared_ptr<GraphicsComponent> b_graphics = make_shared<GraphicsComponent>();
    b_node->addComponent(b_graphics);

    // now combine the local transforms to generate absolute transforms
    TransformMatrixCombiner::combineLocalTransforms(root_node);

    ASSERT_EQ(expected_absolute, *b_graphics->absolute_transform);
}

