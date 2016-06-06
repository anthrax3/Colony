/**
 *   @file: AntGeneratorComponent.h
 *
 *   @date: Jun 6, 2016
 * @author: mateusz
 */

#ifndef SOURCE_ANTGENERATORCOMPONENT_H_
#define SOURCE_ANTGENERATORCOMPONENT_H_

#include "Ant.h"
#include "TimerComponent.h"

/**
 * @class   AntGeneratorComponent
 * @brief   Adds one Ant to the GameObject everytime the timer is fired
 */
class AntGeneratorComponent: public TimerComponent {
public:
    AntGeneratorComponent();
    virtual ~AntGeneratorComponent();
    void fire() override;
};

#endif /* SOURCE_ANTGENERATORCOMPONENT_H_ */
