/**
 *   @file: CircleCircleCollider.h
 *
 *   @date: Jun 16, 2016
 * @author: mateusz
 */

#ifndef SOURCE_CIRCLECIRCLECOLLIDER_H_
#define SOURCE_CIRCLECIRCLECOLLIDER_H_

#include <memory>
#include "CircleColliderItem.h"

class CircleCircleCollider {
public:
    static std::unique_ptr<QVector3D> collide(const std::shared_ptr<CircleColliderItem> &c1, const std::shared_ptr<CircleColliderItem> &c2);
};

#endif /* SOURCE_CIRCLECIRCLECOLLIDER_H_ */
