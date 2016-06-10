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

class PhysicsComponent: public Component {
public:
	// item that represents collision mesh
	std::shared_ptr<ColliderItem> collider_item;

	PhysicsComponent();
	virtual ~PhysicsComponent();
};

#endif /* SOURCE_PHYSICSCOMPONENT_H_ */
