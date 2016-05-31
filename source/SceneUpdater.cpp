/**
 *   @file: SceneUpdater.cpp
 *
 *   @date: May 30, 2016
 * @author: mateusz
 */

#include "SceneUpdater.h"

using namespace std;

SceneUpdater::SceneUpdater() {
}

SceneUpdater::~SceneUpdater() {
}

/**
 * @name    update
 * @brief   Update the scene graph, eg. animation/physics/AI
 * @param   scene_graph_root Where to start the update from
 * @param   dt Delta time in seconds
 */
void SceneUpdater::update(const shared_ptr<GameObject> &scene_graph_root, float dt) const {
    updateSceneNode(scene_graph_root, dt);
}

/**
 * @name    updateSceneNode
 * @brief   Recursively update all components in all scene nodes starting from given root
 * @param   scene_graph_root Where to start the update from
 * @param   dt Delta time in seconds
 */
void SceneUpdater::updateSceneNode(const shared_ptr<GameObject> &node, float dt) const {

    for (auto component : node->components)
        component.second->update(dt);

    for (const auto child : node->children) {
        const auto game_object = static_pointer_cast<GameObject>(child);
        updateSceneNode(game_object, dt);
    }
}
