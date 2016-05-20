/**
 *   @file: Component.h
 *
 *   @date: May 17, 2016
 * @author: Mateusz Midor
 */

#ifndef SOURCE_COMPONENT_H_
#define SOURCE_COMPONENT_H_

#include <memory>
#include "ComponentFinder.h"

/**
 * @class	Component
 * @brief	Building Block of GameObject that represents one aspect of its nature. Eg. Collision/Sound/Graphics
 */
class Component {
protected:
	/**
	 * @name	findComponentByType
	 * @brief	Find a component of desired type residing in the same GameObject
	 * @param	ComponentType Type of desired component
	 * @return	Pointer to component, if exits. Empty pointer otherwise
	 */
	template<class ComponentType>
	std::shared_ptr<ComponentType> findComponentByType() {
		return finder->findComponentByType<ComponentType>();
	}

public:
	// finder allows the component to find other components within the same GameObject
	// handy eg. when collision should result in sound effect
	ComponentFinder *finder;

	Component();
	virtual ~Component();
};

#endif /* SOURCE_COMPONENT_H_ */
