/**
 *   @file: GameObject.h
 *
 *   @date: May 17, 2016
 * @author: Mateusz Midor
 */

#ifndef SOURCE_GAMEOBJECT_H_
#define SOURCE_GAMEOBJECT_H_

#include <memory>
#include <unordered_map>
#include "Component.h"
#include "ComponentFinder.h"
#include "SceneNode.h"

/**
 * @class	GameObject
 * @brief	Makes a building block of game scene. Made up from components that represent aspects of its nature
 */
class GameObject: public ComponentFinder, public SceneNode {
protected:
    std::shared_ptr<Component> findComponentByHashCode(unsigned long long hash) override;

public:
    // hash-to-component map
    std::unordered_map<unsigned long long, std::shared_ptr<Component>> components;

    GameObject();
    virtual ~GameObject();

    void addComponent(const std::shared_ptr<Component> &component);
};

#endif /* SOURCE_GAMEOBJECT_H_ */
