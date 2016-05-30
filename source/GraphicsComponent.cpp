/**
 *   @file: GraphicsComponent.cpp
 *
 *   @date: May 20, 2016
 * @author: Mateusz Midor
 */

#include "GraphicsComponent.h"

using namespace std;

GraphicsComponent::GraphicsComponent() {
}

GraphicsComponent::~GraphicsComponent() {
}

void GraphicsComponent::render(const shared_ptr<QMatrix4x4> &projection) const {
    auto mvp = make_shared<QMatrix4x4>(*projection * *absolute_transform);
    render_item->render(mvp);
}
