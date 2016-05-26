/**
 *   @file: GraphicsComponent.cpp
 *
 *   @date: May 20, 2016
 * @author: Mateusz Midor
 */

#include "GraphicsComponent.h"

GraphicsComponent::GraphicsComponent() {
}

GraphicsComponent::~GraphicsComponent() {
}

void GraphicsComponent::render() const {
    // TODO: apply absolute_transform
    render_item->render();
}
