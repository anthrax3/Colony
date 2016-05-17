/**
 *   @file: GameObject.h
 *
 *   @date: May 17, 2016
 * @author: Mateusz Midor
 */

#ifndef SOURCE_GAMEOBJECT_H_
#define SOURCE_GAMEOBJECT_H_

#include <map>
#include <memory>
#include <cstddef> // size_t
#include "Component.h"

class GameObject {
    std::map<std::size_t, std::shared_ptr<Component>> components;

public:
    GameObject();
    virtual ~GameObject();

    /**
     * @brief Add new component to the GameObject. Note: the compoment type must be unique within GameObject
     * @param component Componen to be added
     */
    void addComponent(const std::shared_ptr<Component> &component);

    /**
     * @brief Return a component of desired type if such exists in GameObject. Empty pointer otherwise
     * @param ComponentType Type of desired component
     */
    template<class ComponentType>
    std::shared_ptr<ComponentType> getComponentByType() {
        auto hash = typeid(ComponentType).hash_code();
        auto result = components.find(hash);

        // component found. Return pointer
        if (result != components.end())
            return std::static_pointer_cast<ComponentType>(result->second);

        // component not found. Return empty pointer
        return std::shared_ptr<ComponentType>();
    }
};

#endif /* SOURCE_GAMEOBJECT_H_ */
