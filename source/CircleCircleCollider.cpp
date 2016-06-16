/**
 *   @file: CircleCircleCollider.cpp
 *
 *   @date: Jun 16, 2016
 * @author: mateusz
 */

#include "CircleCircleCollider.h"

using namespace std;

unique_ptr<QVector3D> CircleCircleCollider::collide(const shared_ptr<CircleColliderItem> &c1, const shared_ptr<CircleColliderItem> &c2) {
    QVector3D &position1 = c1->absolute_center;
    QVector3D &position2 = c2->absolute_center;
    float &radius1 = c1->radius;
    float &radius2 = c2->radius;

    // if two circles collide - return ptr to normal vector of collision plane
    if (position2.distanceToPoint(position1) <= radius1 + radius2)
        return make_unique<QVector3D>((position1 - position2).normalized());

    // no collision. Return empty pointer
    return unique_ptr<QVector3D>();
}
