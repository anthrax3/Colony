/**
 *   @file: LocalTransformComponent.cpp
 *
 *   @date: May 20, 2016
 * @author: Mateusz Midor
 */

#include "LocalTransformComponent.h"

LocalTransformComponent::LocalTransformComponent() {
	translate = QVector3D(0.0f, 0.0f, 0.0f);
	rotate = QVector3D(0.0f, 0.0f, 0.0f);
	scale = QVector3D(1.0f, 1.0f, 1.0f);
}

LocalTransformComponent::~LocalTransformComponent() {
}

/**
 * @name    getLocalTransform
 * @brief   Build transform matrix from local translation, rotation and scale
 * @return  Local transform matrix
 */
QMatrix4x4 LocalTransformComponent::getLocalTransform() const {
	QMatrix4x4 m;
	m.translate(translate);
	m.rotate(rotate.x(), 1.0f, 0.0f, 0.0f);
	m.rotate(rotate.y(), 0.0f, 1.0f, 0.0f);
	m.rotate(rotate.z(), 0.0f, 0.0f, 1.0f);
	m.scale(scale);
	return m;
}
