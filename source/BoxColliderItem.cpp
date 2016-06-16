/**
 *   @file: BoxColliderItem.cpp
 *
 *   @date: Jun 14, 2016
 * @author: mateusz
 */

#include "BoxColliderItem.h"

BoxColliderItem::BoxColliderItem() :
        is_inverted(false) {

    // make up collision planes
    absolute_collision_planes[0] = {&absolute_b2, &absolute_b1, &absolute_a1};
    absolute_collision_planes[1] = {&absolute_c2, &absolute_c1, &absolute_b1};
    absolute_collision_planes[2] = {&absolute_d2, &absolute_d1, &absolute_c1};
    absolute_collision_planes[3] = {&absolute_a2, &absolute_a1, &absolute_d1};
}

BoxColliderItem::BoxColliderItem(QVector3D origin, float witdh, float height, float depth) :
        BoxColliderItem() {

    /*
     * b ---------- c
     *  |          |
     *  |          |
     *  |          |
     *  |          |
     *  |          |
     * a ----------d
     */
    QVector3D x(1, 0, 0);
    QVector3D y(0, 1, 0);
    QVector3D z(0, 0, 1);

    // calc box corner vertices
    a1 = origin;
    b1 = origin + y * height;
    c1 = origin + x * witdh + y * height;
    d1 = origin + x * witdh;

    a2 = origin + z * depth;
    b2 = origin + y * height + z * depth;
    c2 = origin + x * witdh + y * height + z * depth;
    d2 = origin + x * witdh + z * depth;

    // transform the vertices by identity matrix to produce absolute positions
    updateCollisionMesh(QMatrix4x4());
}

BoxColliderItem::~BoxColliderItem() {
}

void BoxColliderItem::updateCollisionMesh(const QMatrix4x4 &absolute) {
    absolute_a1 = absolute * a1;
    absolute_b1 = absolute * b1;
    absolute_c1 = absolute * c1;
    absolute_d1 = absolute * d1;

    absolute_a2 = absolute * a2;
    absolute_b2 = absolute * b2;
    absolute_c2 = absolute * c2;
    absolute_d2 = absolute * d2;
}
