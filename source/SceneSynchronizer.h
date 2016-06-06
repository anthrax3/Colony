/**
 *   @file: SceneSynchronizer.h
 *
 *   @date: Jun 6, 2016
 * @author: mateusz
 */

#ifndef SOURCE_SCENESYNCHRONIZER_H_
#define SOURCE_SCENESYNCHRONIZER_H_

#include <memory>
#include "SceneNode.h"

/**
 * @class   SceneSynchronizer
 * @brief   Executes buffered SceneNode operations like child node addition
 */
class SceneSynchronizer {
    void syncSceneNode(const std::shared_ptr<SceneNode> &node) const;

public:

    void sync(const std::shared_ptr<SceneNode> &scene_graph_root) const;
};

#endif /* SOURCE_SCENESYNCHRONIZER_H_ */
