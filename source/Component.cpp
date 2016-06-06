/**
 *   @file: Component.cpp
 *
 *   @date: May 17, 2016
 * @author: Mateusz Midor
 */

#include "Component.h"

Component::Component() :
        finder(nullptr), owner(nullptr) {
}

Component::~Component() {
}

/**
 * @name    update
 * @brief   Update the component state
 * @param   delta_time Seconds elapsed since last update
 * @note    run from main (GUI) thread
 */
void Component::update(float delta_time) {
    // default empty implenentation
}
