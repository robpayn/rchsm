/*
 * BehBoundTime.h
 */

#ifndef CHSM_RESOURCES_TIME_BEHBOUNDTIME_H_
#define CHSM_RESOURCES_TIME_BEHBOUNDTIME_H_

#include "../../../CHSM/Behavior.h"

class BehBoundTime : public Behavior
{
  public:
    // Constructors/Destructor
    
    BehBoundTime();

    // Methods
    
    void createVariables(Machine*, Holon*) override;
    
    void createVariables(Machine*, Holon*, double);
};

#endif /* CHSM_RESOURCES_TIME_BEHBOUNDTIME_H_ */
