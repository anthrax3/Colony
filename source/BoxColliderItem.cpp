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
    collision_planes[0] = {&a1, &b1, &b2};
    collision_planes[1] = {&b1, &c1, &c2};
    collision_planes[2] = {&c1, &d1, &d2};
    collision_planes[3] = {&d1, &a1, &a2};
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
}

BoxColliderItem::~BoxColliderItem() {
}
