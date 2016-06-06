/**
 *   @file: SceneSynchronizer.cpp
 *
 *   @date: Jun 6, 2016
 * @author: mateusz
 */

#include "SceneSynchronizer.h"

/**
 * @name    sync
 * @brief   Executes buffered SceneNode operations. Good to separate logic thread and render thread
 * @note    Run it during render thread-logic thread synchronization
 * @param   scene_graph_root Where to start the synchronization from
 */
void SceneSynchronizer::sync(const std::shared_ptr<SceneNode> &scene_graph_root) const {
    syncSceneNode(scene_graph_root);
}

void SceneSynchronizer::syncSceneNode(const std::shared_ptr<SceneNode> &node) const {
    node->bufferSync();

    for (const auto child : node->children) {
        syncSceneNode(child);
    }
}
