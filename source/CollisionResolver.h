/**
 *   @file: CollisionResolver.h
 *
 *   @date: Jun 10, 2016
 * @author: mateusz
 */

#ifndef SOURCE_COLLISIONRESOLVER_H_
#define SOURCE_COLLISIONRESOLVER_H_

#include <set>
#include <tuple>
#include <unordered_map>
#include <functional>
#include <memory>
#include <QtGui/QVector3D>
#include <QtGui/QMatrix4x4>
#include "GameObject.h"
#include "ColliderItem.h"
#include "BoxColliderItem.h"
#include "CircleColliderItem.h"
#include "PhysicsComponent.h"
#include "MultiMethod.h"
/**
 * @class   CollisionResolver
 * @brief   keeps track of all colliders on the scene and allows check if given collider collides with sth
 */
class CollisionResolver: public GameObject {

    MultiMethod<const std::shared_ptr<ColliderItem>&, const std::shared_ptr<ColliderItem>&, std::unique_ptr<QVector3D>> collisionMultiMethod;

	void registerCollisionFunctions();
	static std::unique_ptr<QVector3D> collideCircleCircle(const std::shared_ptr<ColliderItem> &c1, const std::shared_ptr<ColliderItem> &c2);
	static std::unique_ptr<QVector3D> collideCircleBox(const std::shared_ptr<ColliderItem> &c1, const std::shared_ptr<ColliderItem> &c2);
	static std::unique_ptr<QVector3D> collideBoxBox(const std::shared_ptr<ColliderItem> &c1, const std::shared_ptr<ColliderItem> &c2);

public:
    CollisionResolver();
    virtual ~CollisionResolver();

    void addCollider(const std::shared_ptr<ColliderItem> &collider);

    void removeCollider(const std::shared_ptr<ColliderItem> &collider);

    std::unique_ptr<QVector3D> resolveCollision(const std::shared_ptr<ColliderItem> &collider);

    std::set<std::shared_ptr<ColliderItem>> colliders;
};

#endif /* SOURCE_COLLISIONRESOLVER_H_ */
