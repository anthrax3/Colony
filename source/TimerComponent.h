/**
 *   @file: TimerComponent.h
 *
 *   @date: Jun 6, 2016
 * @author: mateusz
 */

#ifndef SOURCE_TIMERCOMPONENT_H_
#define SOURCE_TIMERCOMPONENT_H_

#include "Component.h"

class TimerComponent: public Component {
public:
    float time_elapsed;
    float time_interval;
    bool enabled;

    TimerComponent();
    virtual ~TimerComponent();

    void update(float delta_time) override;
    virtual void fire() = 0;
};

#endif /* SOURCE_TIMERCOMPONENT_H_ */
