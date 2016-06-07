/**
 *   @file: GranaryComponent.h
 *
 *   @date: Jun 7, 2016
 * @author: mateusz
 */

#ifndef SOURCE_GRANARYCOMPONENT_H_
#define SOURCE_GRANARYCOMPONENT_H_

#include "Component.h"

/**
 * @class   GranaryComponent
 * @brief   Represents an AntHill resource storage. Eg for food
 */
class GranaryComponent: public Component {
public:
    virtual ~GranaryComponent();
    GranaryComponent();

    // food stock
    unsigned int food;
};

#endif /* SOURCE_GRANARYCOMPONENT_H_ */
