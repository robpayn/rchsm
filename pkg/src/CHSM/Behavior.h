/*
 * Behavior.h
 */

#ifndef RCHSM_BEHAVIOR_H_
#define RCHSM_BEHAVIOR_H_

#include "Holon.h"

class Behavior
{
  public:
    virtual void createVariables(Holon* holon) = 0;
};

#endif /* RCHSM_BEHAVIOR_H_ */
