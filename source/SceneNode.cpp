/*
 * SceneNode.cpp
 *
 *  Created on: May 15, 2016
 *      Author: mateusz
 */


#include "SceneNode.h"

using namespace std;

SceneNode::~SceneNode() {
	// nothing to do here
}

SceneNode::SceneNode() : parent(nullptr) {
}

void SceneNode::addChild(const shared_ptr<SceneNode> child) {
    child->parent = this;
    children.push_back(child);
}
