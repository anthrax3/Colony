/**
 *   @file: CircleBoxCollider.h
 *
 *   @date: Jun 16, 2016
 * @author: mateusz
 */

#ifndef SOURCE_CIRCLEBOXCOLLIDER_H_
#define SOURCE_CIRCLEBOXCOLLIDER_H_

#include <memory>
#include "BoxColliderItem.h"
#include "CircleColliderItem.h"

class CircleBoxCollider {
public:
    static std::unique_ptr<QVector3D> collide(const std::shared_ptr<CircleColliderItem> &c1, const std::shared_ptr<BoxColliderItem> &c2);
};

#endif /* SOURCE_CIRCLEBOXCOLLIDER_H_ */
