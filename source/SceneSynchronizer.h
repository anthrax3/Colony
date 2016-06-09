/**
 *   @file: SceneSynchronizer.h
 *
 *   @date: Jun 6, 2016
 * @author: mateusz
 */

#ifndef SOURCE_SCENESYNCHRONIZER_H_
#define SOURCE_SCENESYNCHRONIZER_H_

#include <memory>
#include <QtGui/QMatrix4x4>
#include "SceneNode.h"
#include "GameObject.h"

/**
 * @class   SceneSynchronizer
 * @brief   Logic thread to render thread data synchronization is handled here
 */
class SceneSynchronizer {
    void syncSceneNodeOperations(const std::shared_ptr<SceneNode> &node) const;
    void syncAbsoluteTransforms(const std::shared_ptr<GameObject> &node, std::shared_ptr<QMatrix4x4> absolute) const;
public:

    void sync(const std::shared_ptr<GameObject> &scene_graph_root) const;
};

#endif /* SOURCE_SCENESYNCHRONIZER_H_ */
