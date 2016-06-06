/**
 *   @file: SimpleAntDriver.h
 *
 *   @date: Jun 5, 2016
 * @author: mateusz
 */

#ifndef SOURCE_SIMPLEANTDRIVER_H_
#define SOURCE_SIMPLEANTDRIVER_H_

#include <QtGui/QVector2D>
#include "Component.h"

/**
 * @class   SimpleAntDriver
 * @brief   Moves the ant around the place in no specific purpose
 */
class SimpleAntDriver: public Component {
public:
    // movement direction
    QVector2D direction;

    // movement speed
    float speed;

    SimpleAntDriver();
    virtual ~SimpleAntDriver();

    void update(float delta_time) override;
};

#endif /* SOURCE_SIMPLEANTDRIVER_H_ */
