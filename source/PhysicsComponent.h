/**
 *   @file: PhysicsComponent.h
 *
 *   @date: Jun 10, 2016
 * @author: mateusz
 */

#ifndef SOURCE_PHYSICSCOMPONENT_H_
#define SOURCE_PHYSICSCOMPONENT_H_

#include <memory>
#include "Component.h"
#include "ColliderItem.h"

/**
 * @class   PhysicsComponent
 * @brief   This class represents physics properties of object. Also collision mesh
 * @note    This component needs LocalTransformComponent for collision to work
 */
class PhysicsComponent: public Component {
    bool collider_registered;

public:
	// item that represents collision mesh
	std::shared_ptr<ColliderItem> collider_item;

	PhysicsComponent();
	virtual ~PhysicsComponent();

	void update(float delta_time) override;
};

#endif /* SOURCE_PHYSICSCOMPONENT_H_ */
