/*
 * BehBoundTime.h
 */

#ifndef RCHSM_TIME_BEHAVIOR_BOUND_H_
#define RCHSM_TIME_BEHAVIOR_BOUND_H_

#include "../../../CHSM/Behavior.h"

class BehBoundTime : public Behavior
{
  public:
    // Constructors/Destructor
    
    BehBoundTime();

    // Methods
    
    void createVariables(Holon* holon) override;
};

#endif /* RCHSM_TIME_BEHAVIOR_BOUND_H_ */
