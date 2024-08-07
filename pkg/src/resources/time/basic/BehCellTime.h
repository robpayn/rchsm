/*
 * BehCellTime.h
 */

#ifndef CHSM_RESOURCES_TIME_BASIC_BEHCELLTIME_H_
#define CHSM_RESOURCES_TIME_BASIC_BEHCELLTIME_H_

#include "../../../CHSM/Behavior.h"

class BehCellTime : public Behavior
{
  public:
    // Constructors/Destructor
    
    BehCellTime();

    // Methods
    
    void createVariables(Machine*, Holon*) override;
};

#endif /* CHSM_RESOURCES_TIME_BASIC_BEHCELLTIME_H_ */
