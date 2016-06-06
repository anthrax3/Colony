/**
 *   @file: TimerComponent.cpp
 *
 *   @date: Jun 6, 2016
 * @author: mateusz
 */

#include "TimerComponent.h"

TimerComponent::TimerComponent() {
    time_elapsed = 0.0f;
    time_interval = 0.0f;
    enabled = false;
}

TimerComponent::~TimerComponent() {
}

void TimerComponent::update(float delta_time) {
    if (!enabled)
        return;

    time_elapsed += delta_time;
    if (time_elapsed > time_interval) {
        fire();
        time_elapsed = 0.0f;
    }
}
