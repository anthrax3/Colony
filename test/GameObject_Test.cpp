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
class GraphicsComponent: public Component {
};
class PhysicsComponent: public Component {
};
class AIComponent: public Component {
};

TEST(GameObject_Test, add_then_find_component) {
    GameObject o;
    o.addComponent(make_shared<GraphicsComponent>());
    o.addComponent(make_shared<PhysicsComponent>());
    o.addComponent(make_shared<AIComponent>());

    auto graphics_found = o.findComponentByType<GraphicsComponent>();
    auto physics_found = o.findComponentByType<PhysicsComponent>();
    auto ai_found = o.findComponentByType<AIComponent>();

    EXPECT_TRUE(graphics_found);
    EXPECT_TRUE(physics_found);
    EXPECT_TRUE(ai_found);
}
