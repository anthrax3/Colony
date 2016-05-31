/**
 *   @file: SceneUpdater.h
 *
 *   @date: May 30, 2016
 * @author: mateusz
 */

#ifndef SOURCE_SCENEUPDATER_H_
#define SOURCE_SCENEUPDATER_H_

#include <memory>
#include "GameObject.h"

/**
 * @class   SceneUpdater
 * @brief   Updates the scene graph, used for eg. animation/physics/AI
 */
class SceneUpdater {
    void updateSceneNode(const std::shared_ptr<GameObject> &node, float dt) const;

public:
    SceneUpdater();
    virtual ~SceneUpdater();

    void update(const std::shared_ptr<GameObject> &scene_graph_root, float dt) const;
};

#endif /* SOURCE_SCENEUPDATER_H_ */
