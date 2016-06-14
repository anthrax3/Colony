/**
 *   @file: CircleColliderItem.cpp
 *
 *   @date: Jun 10, 2016
 * @author: mateusz
 */

#include "CircleColliderItem.h"

CircleColliderItem::CircleColliderItem(float radius) : radius(radius) {
}

CircleColliderItem::~CircleColliderItem() {
}

void CircleColliderItem::updateCollisionMesh(const QMatrix4x4 &absolute) {
    absolute_center = absolute.column(3).toVector3D();
}
