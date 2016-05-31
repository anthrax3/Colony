/**
 *   @file: RotatorComponent.h
 *
 *   @date: May 30, 2016
 * @author: mateusz
 */

#ifndef SOURCE_ROTATORCOMPONENT_H_
#define SOURCE_ROTATORCOMPONENT_H_

#include <QtGui/QVector3D>
#include "Component.h"
#include "LocalTransformComponent.h"

/**
 * @class   RotatorComponent
 * @brief   Attached to GameObjec, automatically rotates the LocalTransformComponent during update
 */
class RotatorComponent: public Component {
    std::shared_ptr<LocalTransformComponent> transform;
public:
    QVector3D rotate;

    RotatorComponent();
    virtual ~RotatorComponent();

    void update(float dt) override;
};

#endif /* SOURCE_ROTATORCOMPONENT_H_ */
