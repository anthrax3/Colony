/**
 *   @file: TransformMatrixCombiner.h
 *
 *   @date: May 20, 2016
 * @author: Mateusz Midor
 */

#ifndef SOURCE_TRANSFORMMATRIXCOMBINER_H_
#define SOURCE_TRANSFORMMATRIXCOMBINER_H_

#include <QtGui/QMatrix4x4>
#include <memory>

#include "GameObject.h"

/**
 * @class   TransformMatrixCombiner
 * @brief   Combines local transforms of SceneNodes to produce absolute transform for each node
 */
class TransformMatrixCombiner {
private:

    static void recursiveCombineTransforms(const std::shared_ptr<GameObject> &node,
            std::shared_ptr<QMatrix4x4> absolute);
public:

    static void combineLocalTransforms(const std::shared_ptr<GameObject> &root);
};

#endif /* SOURCE_TRANSFORMMATRIXCOMBINER_H_ */
