/**
 *   @file: SceneNode.h
 *
 *   @date: May 15, 2016
 * @author: Mateusz Midor
 */

#include "SceneNode.h"

using namespace std;


SceneNode::SceneNode() :
		parent(nullptr) {
}

SceneNode::~SceneNode() {
}

/**
 * @name	addChild
 * @brief	Add child node to current node and set it's parent to current node
 * @param	child Node to be added
 */
void SceneNode::addChild(const shared_ptr<SceneNode> child) {
	child->parent = this;
	children.push_back(child);
}
