/**
 *   @file: SceneSynchronizer.cpp
 *
 *   @date: Jun 6, 2016
 * @author: mateusz
 */

#include "LocalTransformComponent.h"
#include "GraphicsComponent.h"
#include "SceneSynchronizer.h"

using namespace std;


/**
 * @name    sync
 * @brief   Logic-thread to render-thread data synchronization happens here
 * @note    Run it during render thread-logic thread synchronization
 * @param   scene_graph_root Where to start the synchronization from
 */
void SceneSynchronizer::sync(const std::shared_ptr<GameObject> &scene_graph_root) const {
    // 1.
    syncSceneNodeOperations(scene_graph_root);

    // 2.
    syncAbsoluteTransforms(scene_graph_root, make_shared<QMatrix4x4>());
}

/**
 * @name    syncSceneNodeOperations
 * @brief   Executes buffered SceneNode operations
 * @param   scene_graph_root Where to start the synchronization from
 */
void SceneSynchronizer::syncSceneNodeOperations(const std::shared_ptr<SceneNode> &node) const {
    node->bufferSync();

    for (const auto child : node->children) {
        syncSceneNodeOperations(child);
    }
}

/**
 * @name    syncAbsoluteTransforms
 * @brief   simply copies absolut_transform from Transform component to Graphics component
 * @param   scene_graph_root Where to start the synchronization from
 * @param   absolute Parent node absolute transform matrix
 */
void SceneSynchronizer::syncAbsoluteTransforms(const shared_ptr<GameObject> &node,
        shared_ptr<QMatrix4x4> absolute) const {
    if (auto transform_component = node->findComponentByType<LocalTransformComponent>())
        absolute = make_shared<QMatrix4x4>(transform_component->absolute_transform);

    if (auto graphics_component = node->findComponentByType<GraphicsComponent>())
        graphics_component->absolute_transform = absolute;

    for (const auto child : node->children) {
        auto game_object = static_pointer_cast<GameObject>(child);
        syncAbsoluteTransforms(game_object, absolute);
    }
}
