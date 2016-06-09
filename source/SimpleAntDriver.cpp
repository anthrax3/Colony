/**
 *   @file: SimpleAntDriver.cpp
 *
 *   @date: Jun 5, 2016
 * @author: mateusz
 */

#include <random>
#include <memory>
#include <cmath>
#include "SimpleAntDriver.h"
#include "LocalTransformComponent.h"

using namespace std;

/**
 * @brief   Constructor. Here we give the ant an initial speed and direction of movement
 */
SimpleAntDriver::SimpleAntDriver() {
    random_device rd;
    default_random_engine engine(rd()); // use random_device to seed the generator

    uniform_int_distribution<unsigned> random_speed(10, 70);
    speed = random_speed(engine);

    uniform_int_distribution<int> random_dir(-100, 100);
    direction.setX(random_dir(engine));
    direction.setY(random_dir(engine));
    direction.normalize();
}

SimpleAntDriver::~SimpleAntDriver() {
}

/**
 * @name    update
 * @brief   Here the ant makes a step forward at its own pace
 * @param   delta_time Delta time in seconds from previous update
 */
void SimpleAntDriver::update(float delta_time) {
    if (auto transform = findComponentByType<LocalTransformComponent>()) {
        QVector4D next_position = transform->absolute_transform.column(3) + direction * speed * delta_time;

        if ((next_position.x() <= 0) || (next_position.x() > 320))
            direction.setX(-direction.x());

        if ((next_position.y() <= 0) || (next_position.y() > 240))
            direction.setY(-direction.y());

        transform->translate += direction * speed * delta_time;

        if (direction.x() == 0.0f)
            transform->rotate.setZ(90.0f);
        else
            transform->rotate.setZ(180.0f / 3.14f * atan(direction.y() / direction.x()));
    }
}
