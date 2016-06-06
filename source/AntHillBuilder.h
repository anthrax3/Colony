/**
 *   @file: AntHillBuilder.h
 *
 *   @date: Jun 6, 2016
 * @author: mateusz
 */

#ifndef SOURCE_ANTHILLBUILDER_H_
#define SOURCE_ANTHILLBUILDER_H_

#include <memory>
#include "GameObject.h"

/**
 * @class   AntHillBuilder
 * @brief   Allows to build a brand new AntHill
 */
class AntHillBuilder {
public:
    static std::shared_ptr<GameObject> buildAntHill(float x, float y);
};

#endif /* SOURCE_ANTHILLBUILDER_H_ */
