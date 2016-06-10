/**
 *   @file: SimpleAntDriver.h
 *
 *   @date: Jun 5, 2016
 * @author: mateusz
 */

#ifndef SOURCE_SIMPLEANTDRIVER_H_
#define SOURCE_SIMPLEANTDRIVER_H_

#include <memory>
#include <QtGui/QVector3D>
#include "CollisionResolver.h"
#include "Component.h"

/**
 * @class   SimpleAntDriver
 * @brief   Moves the ant around the place in no specific purpose
 */
class SimpleAntDriver: public Component {
public:
    // movement direction
    QVector3D direction;

    // movement speed
    float speed;

    // collision_resolver allows the driver to avoid obstacles
    std::shared_ptr<CollisionResolver> collision_resolver;

    SimpleAntDriver();
    virtual ~SimpleAntDriver();

    void update(float delta_time) override;
};

#endif /* SOURCE_SIMPLEANTDRIVER_H_ */
