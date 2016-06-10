/**
 *   @file: CollisionResolver.cpp
 *
 *   @date: Jun 10, 2016
 * @author: mateusz
 */

#include "LocalTransformComponent.h"
#include "CircleColliderItem.h"
#include "CollisionResolver.h"

using namespace std;

CollisionResolver::CollisionResolver() {
}

CollisionResolver::~CollisionResolver() {
}

void CollisionResolver::addCollider(PhysicsComponent *item) {
    colliders.insert(item);
}

void CollisionResolver::removeCollider(PhysicsComponent *item) {
    auto it = find(colliders.begin(), colliders.end(), item);
    if (it != colliders.end())
        colliders.erase(it);
}

unique_ptr<QVector3D> CollisionResolver::resolveCollision(const std::shared_ptr<PhysicsComponent> &physics) {
    auto circle_collider = static_pointer_cast<CircleColliderItem>(physics->collider_item);
    float radius1 = circle_collider->radius;

    auto transform = physics->findComponentByType<LocalTransformComponent>();
    QVector3D position1 = transform->absolute_transform.column(3).toVector3D();

    for (auto p : colliders) {
        if (p == physics.get())
            continue;

        auto circle_collider2 = std::static_pointer_cast<CircleColliderItem>(p->collider_item);
        float radius2 = circle_collider2->radius;

        auto transform2 = p->findComponentByType<LocalTransformComponent>();
        QVector3D position2 = transform2->absolute_transform.column(3).toVector3D();

        if (position2.distanceToPoint(position1) < radius1 + radius2)
            return make_unique<QVector3D>((position2 - position1).normalized());
    }

    return unique_ptr<QVector3D>();
}

/**
 * @name    resolveCollision
 * @brief   check if given collider at given position collides with something
 * @param   collider The collider to be checked. Only CircleColliderItem supported for now
 * @param   position Absolute position of the collider
 * @return  Pointer to normal vector of collision plane in case of collision. Empty pointer otherwise
 */
unique_ptr<QVector3D> CollisionResolver::resolveCollision(const std::shared_ptr<ColliderItem> &collider,
        const QVector3D &position) {

    auto circle_collider = static_pointer_cast<CircleColliderItem>(collider);
    float radius1 = circle_collider->radius;
    const QVector3D &position1 = position;

    for (auto p : colliders) {
        auto circle_collider2 = static_pointer_cast<CircleColliderItem>(p->collider_item);

        // please dont self-collide
        if (circle_collider2 == collider)
            continue;

        float radius2 = circle_collider2->radius;
        auto transform2 = p->findComponentByType<LocalTransformComponent>();
        QVector3D position2 = transform2->absolute_transform.column(3).toVector3D();

        // if two circles collide - return ptr to normal vector of collision plane
        if (position2.distanceToPoint(position1) <= radius1 + radius2)
            return make_unique<QVector3D>((position1 - position2).normalized());
    }

    // no collision. Return empty pointer
    return unique_ptr<QVector3D>();
}
