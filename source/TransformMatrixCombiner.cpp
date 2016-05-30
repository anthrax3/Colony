/**
 *   @file: TransformMatrixCombiner.cpp
 *
 *   @date: May 20, 2016
 * @author: Mateusz Midor
 */

#include "TransformMatrixCombiner.h"
#include "GraphicsComponent.h"
#include "LocalTransformComponent.h"

using namespace std;

/**
 * @name    recursiveCombineTransforms
 * @brief   Calculate node absolute transform by combining parent transform and node local transform
 *          Then recursively process child nodes
 * @param   node SceneNode we are calculating absolute transform for
 * @param   absolute Absolute transform of the node's parent
 */
void TransformMatrixCombiner::recursiveCombineTransforms(const shared_ptr<GameObject> &node,
        shared_ptr<QMatrix4x4> absolute) {

    shared_ptr<GraphicsComponent> graphics_component = node->findComponentByType<GraphicsComponent>();
    auto transform_component = node->findComponentByType<LocalTransformComponent>();

    if (transform_component)
        absolute = make_shared<QMatrix4x4>((*absolute) * transform_component->getMatrix());

    if (graphics_component)
        graphics_component->absolute_transform = absolute;

    for (const auto child : node->children) {
        auto game_object = static_pointer_cast<GameObject>(child);
        recursiveCombineTransforms(game_object, absolute);
    }
}

/**
 * @name    combineLocalTransforms
 * @brief   Calculate node absolute transform by combining local transforms from root down to the node
 * @param   root Work starting point
 */
void TransformMatrixCombiner::combineLocalTransforms(const shared_ptr<GameObject> &root) {
    auto identity = make_shared<QMatrix4x4>();
    identity->setToIdentity();
    recursiveCombineTransforms(root, identity);
}
