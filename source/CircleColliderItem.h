/**
 *   @file: CircleColliderItem.h
 *
 *   @date: Jun 10, 2016
 * @author: mateusz
 */

#ifndef SOURCE_CIRCLECOLLIDERITEM_H_
#define SOURCE_CIRCLECOLLIDERITEM_H_

#include "ColliderItem.h"

class CircleColliderItem: public ColliderItem {
public:
	// circle collision area is defined by circle radius
	float radius;

	CircleColliderItem(float radius = 1.0f);
	virtual ~CircleColliderItem();
};

#endif /* SOURCE_CIRCLECOLLIDERITEM_H_ */
