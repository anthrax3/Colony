/**
 *   @file: SceneNode.h
 *
 *   @date: May 15, 2016
 * @author: Mateusz Midor
 */

#include "SceneNode.h"

using namespace std;

SceneNode::~SceneNode() {
    // nothing to do here
}

SceneNode::SceneNode() :
        parent(nullptr) {
}

void SceneNode::addChild(const shared_ptr<SceneNode> child) {
    child->parent = this;
    children.push_back(child);
}
