/**
 *   @file: Ant.h
 *
 *   @date: Jun 5, 2016
 * @author: mateusz
 */

#ifndef SOURCE_ANT_H_
#define SOURCE_ANT_H_

#include "GameObject.h"

/**
 * @class   Ant
 * @brief   A class representing an Ant, walking around in some anty purpose
 */
class Ant: public GameObject {
public:
    Ant();
    virtual ~Ant();
};

#endif /* SOURCE_ANT_H_ */
