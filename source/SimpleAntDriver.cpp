/**
 *   @file: SimpleAntDriver.cpp
 *
 *   @date: Jun 5, 2016
 * @author: mateusz
 */

#include <random>
#include <memory>
#include <cmath>
#include <iostream>
#include "SimpleAntDriver.h"
#include "LocalTransformComponent.h"
#include "PhysicsComponent.h"
using namespace std;

/**
 * @brief   Constructor. Here we give the ant an initial speed and direction of movement
 */
SimpleAntDriver::SimpleAntDriver() {
    random_device rd;
    default_random_engine engine(rd()); // use random_device to seed the generator

    uniform_int_distribution<unsigned> random_speed(30, 90);
    speed = random_speed(engine);

    uniform_int_distribution<int> random_dir(-100, 100);
    direction.setX(random_dir(engine));
    direction.setY(random_dir(engine));
    direction.normalize();
}

SimpleAntDriver::~SimpleAntDriver() {
}

/**
 * @name    reflect
 * @brief   Mirror d vector against normal
 * @param   d Vector to be reflected
 * @param   normal
 * @return  Reflected vector
 */
QVector3D reflect(const QVector3D &d, const QVector3D &normal) {
    float dot = QVector3D::dotProduct(d, normal);

    // dont reflect if d and normal point the same direction
    if (dot >= 0.0f)
        return d;

    return d - 2 * dot * normal;
}

/**
 * @name    update
 * @brief   Here the ant makes a step forward at its own pace
 * @param   delta_time Delta time in seconds from previous update
 */
void SimpleAntDriver::update(float delta_time) {
    if (!collision_resolver) {
        collision_resolver = owner->findNodeByTypeEverywhere<CollisionResolver>();

        if (collision_resolver)
            std::cout << "Ant:: collision resolver found!" << std::endl;
    }

    if (auto transform = findComponentByType<LocalTransformComponent>()) {
        QVector3D next_position = transform->absolute_transform.column(3).toVector3D();// + direction * speed * delta_time;

        if ((next_position.x() <= 0) || (next_position.x() > 320)) {
            direction.setX(-direction.x());
            //return; // dont move if collision
        }

        if ((next_position.y() <= 0) || (next_position.y() > 240)) {
            direction.setY(-direction.y());
            //return; // dont move if collision
        }

        // stop on collision
        if (collision_resolver)
            if (auto physics = findComponentByType<PhysicsComponent>())
                if (auto bounce_plane = collision_resolver->resolveCollision(physics->collider_item, next_position)) {
                    direction = reflect(direction, *bounce_plane);
                  //  return; // dont move if collision
                }

        transform->translate += direction * speed * delta_time;

        if (direction.x() == 0.0f)
            transform->rotate.setZ(90.0f);
        else
            transform->rotate.setZ(180.0f / 3.14f * atan(direction.y() / direction.x()));
    }
}
