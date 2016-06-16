/**
 *   @file: BoxColliderItem.h
 *
 *   @date: Jun 14, 2016
 * @author: mateusz
 */

#ifndef SOURCE_BOXCOLLIDERITEM_H_
#define SOURCE_BOXCOLLIDERITEM_H_

#include <array>
#include <QtGui/QVector3D>
#include "ColliderItem.h"


class BoxColliderItem: public ColliderItem {
public:
	/*
	 * b ---------- c
	 *  |          |
	 *  |          |
	 *  |          |
	 *  |          |
	 *  |          |
	 * a ----------d
	 */
    QVector3D a1, b1, c1, d1; // top
    QVector3D a2, b2, c2, d2; // bottom

    QVector3D absolute_a1, absolute_b1, absolute_c1, absolute_d1; // top after transform
    QVector3D absolute_a2, absolute_b2, absolute_c2, absolute_d2; // bottom after transform
	using Plane = std::array<QVector3D*, 3>; // 3 vectors make up a plane
	std::array<Plane, 4> absolute_collision_planes; // only side planes of the box for now

	bool is_inverted; // inverted = collides when trying to get outside the box

	BoxColliderItem();
	BoxColliderItem(QVector3D origin, float witdh, float height, float depth);
	virtual ~BoxColliderItem();

	void updateCollisionMesh(const QMatrix4x4 &absolute) override;
};

#endif /* SOURCE_BOXCOLLIDERITEM_H_ */
