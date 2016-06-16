/**
 *   @file: CircleBoxCollider_Test.cpp
 *
 *   @date: Jun 16, 2016
 * @author: mateusz
 */

#include <memory>
#include "gtest/gtest.h"
#include "CircleBoxCollider.h"

using namespace std;

TEST(CircleBoxCollider_Test, circle_collide_box)
{
    // place the circle inside the box
    auto c1 = make_shared<CircleColliderItem>(1.0f);
    c1->absolute_center = QVector3D(5, 5, 5);

    auto c2 = make_shared<BoxColliderItem>(QVector3D(0, 0, 0), 10, 10, 10);
    c2->is_inverted = false;


    EXPECT_TRUE(CircleBoxCollider::collide(c1, c2));
}

TEST(CircleBoxCollider_Test, circle_nocollide_box)
{
    // place the circle outside the box
    auto c1 = make_shared<CircleColliderItem>(1.0f);
    c1->absolute_center = QVector3D(-5, -5, -5);

    auto c2 = make_shared<BoxColliderItem>(QVector3D(0, 0, 0), 10, 10, 10);
    c2->is_inverted = false;


    EXPECT_FALSE(CircleBoxCollider::collide(c1, c2));
}

TEST(CircleBoxCollider_Test, circle_collide_invertedbox)
{
    // place the circle outside the inverted box
    auto c1 = make_shared<CircleColliderItem>(1.0f);
    c1->absolute_center = QVector3D(-5, -5, -5);

    auto c2 = make_shared<BoxColliderItem>(QVector3D(0, 0, 0), 10, 10, 10);
    c2->is_inverted = true;


    EXPECT_TRUE(CircleBoxCollider::collide(c1, c2));
}

TEST(CircleBoxCollider_Test, circle_nocollide_invertedbox)
{
    // place the circle inside the inverted box
    auto c1 = make_shared<CircleColliderItem>(1.0f);
    c1->absolute_center = QVector3D(5, 5, 5);

    auto c2 = make_shared<BoxColliderItem>(QVector3D(0, 0, 0), 10, 10, 10);
    c2->is_inverted = true;


    EXPECT_FALSE(CircleBoxCollider::collide(c1, c2));
}
