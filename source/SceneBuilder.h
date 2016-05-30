/**
 *   @file: SceneBuilder.h
 *
 *   @date: May 30, 2016
 * @author: mateusz
 */

#ifndef SOURCE_SCENEBUILDER_H_
#define SOURCE_SCENEBUILDER_H_

#include <memory>
#include "GameObject.h"

/**
 * @class   SceneBuilder
 * @brief   A collection of factory methods for simple scene graphs
 */
class SceneBuilder {
public:
    static std::shared_ptr<GameObject> buildCircleFromLines();
};

#endif /* SOURCE_SCENEBUILDER_H_ */
