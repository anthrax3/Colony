/**
 *   @file: ComponentFinder.h
 *
 *   @date: May 18, 2016
 * @author: Mateusz Midor
 */

#ifndef SOURCE_COMPONENTFINDER_H_
#define SOURCE_COMPONENTFINDER_H_

#include <memory>


class Component;

/**
 *  @class 	ComponentFinder
 *  @brief	An interface that allows finding components within GameObject
 *	@note	To be inherited by GameObject
 */
class ComponentFinder {
protected:

	/**
	 * @name	findComponentByHashCode
	 * @brief	Find a component of desired hash code (hash of class)
	 * @param	hash Hash code of desired component
	 * @return	Pointer to component, if exists. Empty pointer otherwise
	 * @note	To be implemented by GameObject
	 */
	virtual std::shared_ptr<Component> findComponentByHashCode(unsigned long long hash) = 0;

public:
	virtual ~ComponentFinder() {}

	/**
	 * @name	findComponentByType
	 * @brief	Find a component of desired type
	 * @param	ComponentType Type of desired component
	 * @return	Pointer to component, if exists. Empty pointer otherwise
	 */
	template<class ComponentType>
	std::shared_ptr<ComponentType> findComponentByType() {
		unsigned long long hash = typeid(ComponentType).hash_code();
		auto result = findComponentByHashCode(hash);
		return std::static_pointer_cast<ComponentType>(result);
	}
};

#endif /* SOURCE_COMPONENTFINDER_H_ */
