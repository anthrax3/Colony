/**
 *   @file: CollisionResolver.h
 *
 *   @date: Jun 10, 2016
 * @author: mateusz
 */

#ifndef SOURCE_COLLISIONRESOLVER_H_
#define SOURCE_COLLISIONRESOLVER_H_

#include <set>
#include <memory>
#include <QtGui/QVector3D>
#include <QtGui/QMatrix4x4>
#include "GameObject.h"
#include "ColliderItem.h"
#include "PhysicsComponent.h"

/**
 * @class   CollisionResolver
 * @brief   keeps track of all colliders on the scene and allows check if given collider collides with sth
 */
class CollisionResolver: public GameObject {
public:
    CollisionResolver();
    virtual ~CollisionResolver();

    void addCollider(PhysicsComponent *item);

    void removeCollider(PhysicsComponent *item);

    std::unique_ptr<QVector3D> resolveCollision(const std::shared_ptr<PhysicsComponent> &physics);

    std::unique_ptr<QVector3D> resolveCollision(const std::shared_ptr<ColliderItem> &collider,
            const QVector3D &position);

    std::set<PhysicsComponent*> colliders;
};

#endif /* SOURCE_COLLISIONRESOLVER_H_ */
