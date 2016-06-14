/**
 *   @file: CircleColliderItem.h
 *
 *   @date: Jun 10, 2016
 * @author: mateusz
 */

#ifndef SOURCE_CIRCLECOLLIDERITEM_H_
#define SOURCE_CIRCLECOLLIDERITEM_H_

#include <QtGui/QVector3D>
#include "ColliderItem.h"

class CircleColliderItem: public ColliderItem {
public:
	// circle collision area is defined by circle radius
	float radius;
	QVector3D absolute_center;

	CircleColliderItem(float radius = 1.0f);
	virtual ~CircleColliderItem();

	void updateCollisionMesh(const QMatrix4x4 &absolute) override;
};

#endif /* SOURCE_CIRCLECOLLIDERITEM_H_ */
