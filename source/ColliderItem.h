/**
 *   @file: ColliderItem.h
 *
 *   @date: Jun 10, 2016
 * @author: mateusz
 */

#ifndef SOURCE_COLLIDERITEM_H_
#define SOURCE_COLLIDERITEM_H_

#include <QtGui/QMatrix4x4>

class ColliderItem {
public:
	ColliderItem();
	virtual ~ColliderItem();

	virtual void updateCollisionMesh(const QMatrix4x4 &absolute) = 0;
};

#endif /* SOURCE_COLLIDERITEM_H_ */
