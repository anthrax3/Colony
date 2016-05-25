/**
 *   @file: GraphicsComponent.h
 *
 *   @date: May 20, 2016
 * @author: Mateusz Midor
 */

#ifndef SOURCE_GRAPHICSCOMPONENT_H_
#define SOURCE_GRAPHICSCOMPONENT_H_

#include <QtGui/QMatrix4x4>
#include <memory>
#include "Component.h"
#include "RenderItem.h"
#include <iostream>
/**
 * @class	GraphicsComponent
 * @brief	Represents graphical aspect of GameObject together with its absolute transform
 */
class GraphicsComponent : public Component {
public:
	// absolute transform; it is a combination of transform matrices from superior scene nodes
	std::shared_ptr<QMatrix4x4> absolute_transform;

	// item that can be updated, prepared and rendered
	std::shared_ptr<RenderItem> render_item;

	GraphicsComponent();
	virtual ~GraphicsComponent();

};

#endif /* SOURCE_GRAPHICSCOMPONENT_H_ */
