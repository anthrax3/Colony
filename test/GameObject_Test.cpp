/**
 *   @file: GameObject_Test.cpp
 *
 *   @date: May 17, 2016
 * @author: Mateusz Midor
 */

#include <memory>
#include "gtest/gtest.h"
#include "GameObject.h"

using namespace std;

// A couple of Component descendants to test GameObject as component container
class _GraphicsComponent: public Component {
};
class _PhysicsComponent: public Component {
};
class _AIComponent: public Component {
};

TEST(GameObject_Test, add_then_find_component) {
    GameObject o;

    o.addComponent(make_shared<_GraphicsComponent>());
    o.addComponent(make_shared<_PhysicsComponent>());
    o.addComponent(make_shared<_AIComponent>());

    auto graphics_found = o.findComponentByType<_GraphicsComponent>();
    auto physics_found = o.findComponentByType<_PhysicsComponent>();
    auto ai_found = o.findComponentByType<_AIComponent>();

    EXPECT_TRUE(graphics_found);
    EXPECT_TRUE(physics_found);
    EXPECT_TRUE(ai_found);
}
