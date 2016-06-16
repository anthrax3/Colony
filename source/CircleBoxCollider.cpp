/**
 *   @file: CircleBoxCollider.cpp
 *
 *   @date: Jun 16, 2016
 * @author: mateusz
 */

#include <iostream>
#include "CircleBoxCollider.h"

using namespace std;

unique_ptr<QVector3D> collideCircleInvertedBox(const shared_ptr<CircleColliderItem> &c1, const shared_ptr<BoxColliderItem> &c2) {
    QVector3D &position = c1->absolute_center;
    for (const BoxColliderItem::Plane &plane : c2->absolute_collision_planes)
        if (position.distanceToPlane(*plane[0], *plane[1], *plane[2]) >= 0.0f) {
            cout << __FUNCTION__ << ": inverted collide!" << endl;
            // invert the normal as it is inverted box
            return make_unique<QVector3D>(-QVector3D::normal(*plane[0], *plane[1], *plane[2]));
        }

    // no collision. Return empty pointer
    return unique_ptr<QVector3D>();
}

unique_ptr<QVector3D> collideCircleRegularBox(const shared_ptr<CircleColliderItem> &c1, const shared_ptr<BoxColliderItem> &c2) {
    QVector3D position = c1->absolute_center;
    float min_distance = -99999999.0f;
    BoxColliderItem::Plane min_distance_plane;

    for (const BoxColliderItem::Plane &plane : c2->absolute_collision_planes) {
        float distance = position.distanceToPlane(*plane[0], *plane[1], *plane[2]);

        // outside the box. No collision
        if (distance > 0.0f)
            return unique_ptr<QVector3D>();

        // remember this plane if its closer to our position
        if (distance > min_distance) {
            min_distance = distance;
            min_distance_plane = plane;
        }
    }

    return make_unique<QVector3D>(QVector3D::normal(*min_distance_plane[0], *min_distance_plane[1], *min_distance_plane[2]));
}

unique_ptr<QVector3D> CircleBoxCollider::collide(const shared_ptr<CircleColliderItem> &c1, const shared_ptr<BoxColliderItem> &c2) {
    if (c2->is_inverted)
        return collideCircleInvertedBox(c1, c2);
    else
        return collideCircleRegularBox(c1, c2);
}
