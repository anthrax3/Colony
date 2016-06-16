/**
 *   @file: CollisionResolver.cpp
 *
 *   @date: Jun 10, 2016
 * @author: mateusz
 */

#include <typeinfo>
#include <iostream>
#include "LocalTransformComponent.h"
#include "CollisionResolver.h"
#include "CircleCircleCollider.h"
#include "CircleBoxCollider.h"

using namespace std;

CollisionResolver::CollisionResolver() {
    registerCollisionFunctions();
}

CollisionResolver::~CollisionResolver() {
}

void CollisionResolver::addCollider(const shared_ptr<ColliderItem> &collider) {
    colliders.insert(collider);
}

void CollisionResolver::removeCollider(const shared_ptr<ColliderItem> &collider) {
    auto it = find(colliders.begin(), colliders.end(), collider);
    if (it != colliders.end())
        colliders.erase(it);
}

/**
 * @name    resolveCollision
 * @brief   check if given collider at given position collides with something
 * @param   collider The collider to be checked. Only CircleColliderItem supported for now
 * @param   position Absolute position of the collider
 * @return  Pointer to normal vector of collision plane in case of collision. Empty pointer otherwise
 */
unique_ptr<QVector3D> CollisionResolver::resolveCollision(const shared_ptr<ColliderItem> &collider1) {
    for (const auto collider2 : colliders) {
        // please dont self-collide
        if (collider2 == collider1)
            continue;

        if (auto collision_plane = collisionMultiMethod.dispatch(collider1, collider2))
            return collision_plane;
    }

    return unique_ptr<QVector3D>();
}

void CollisionResolver::registerCollisionFunctions() {
    collisionMultiMethod.addMethod<const shared_ptr<CircleColliderItem> &, const shared_ptr<CircleColliderItem> &>(collideCircleCircle);
    collisionMultiMethod.addMethod<const shared_ptr<CircleColliderItem> &, const shared_ptr<BoxColliderItem> &>(collideCircleBox);
    collisionMultiMethod.addMethodReverseParams<const shared_ptr<BoxColliderItem> &, const shared_ptr<CircleColliderItem> &>(collideCircleBox);
    collisionMultiMethod.addMethod<const shared_ptr<BoxColliderItem> &, const shared_ptr<BoxColliderItem> &>(collideCircleBox);
}

unique_ptr<QVector3D> CollisionResolver::collideCircleCircle(const shared_ptr<ColliderItem> &c1, const shared_ptr<ColliderItem> &c2) {
    auto cc1 = static_pointer_cast<CircleColliderItem>(c1);
    auto cc2 = static_pointer_cast<CircleColliderItem>(c2);

    return CircleCircleCollider::collide(cc1, cc2);
}


unique_ptr<QVector3D> CollisionResolver::collideCircleBox(const shared_ptr<ColliderItem> &c1, const shared_ptr<ColliderItem> &c2) {
    auto cc = static_pointer_cast<CircleColliderItem>(c1);
    auto bc = static_pointer_cast<BoxColliderItem>(c2);

    return CircleBoxCollider::collide(cc, bc);
}

unique_ptr<QVector3D> CollisionResolver::collideBoxBox(const shared_ptr<ColliderItem> &c1, const shared_ptr<ColliderItem> &c2) {
    cout << __FUNCTION__ << ": not implemented yet" << endl;
    // no collision. Return empty pointer
    return unique_ptr<QVector3D>();
}
