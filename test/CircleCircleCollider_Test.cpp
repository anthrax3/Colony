/**
 *   @file: CircleCircleCollider_Test.cpp
 *
 *   @date: Jun 16, 2016
 * @author: mateusz
 */

#include <memory>
#include "gtest/gtest.h"
#include "CircleCircleCollider.h"

using namespace std;

TEST(CircleCircleCollider_Test, circle_collide_circle)
{
    auto c1 = make_shared<CircleColliderItem>(1.0f);
    c1->absolute_center = QVector3D(0, 0, 0);

    auto c2 = make_shared<CircleColliderItem>(1.0f);
    c2->absolute_center = QVector3D(1, 0, 0);


    EXPECT_TRUE(CircleCircleCollider::collide(c1, c2));
}

TEST(CircleCircleCollider_Test, circle_nocollide_circle)
{
    auto c1 = make_shared<CircleColliderItem>(1.0f);
    c1->absolute_center = QVector3D(0, 0, 0);

    auto c2 = make_shared<CircleColliderItem>(1.0f);
    c2->absolute_center = QVector3D(3, 0, 0);


    EXPECT_FALSE(CircleCircleCollider::collide(c1, c2));
}
