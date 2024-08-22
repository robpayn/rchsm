/*
 * BehCellTime.h
 */

#ifndef RESOURCES_TIME_BASIC_BEHCELLTIME_H_
#define RESOURCES_TIME_BASIC_BEHCELLTIME_H_

#include "../../../CHSM/Behavior.h"

class BehCellTime : public Behavior
{
  public:
    // Constructors/Destructor
    
    BehCellTime();

    // Methods
    
    void createVariables(Machine*, Holon*) override;
    
    void createVariables(Machine*, Holon*, double, long, bool);
};

#endif /* RESOURCES_TIME_BASIC_BEHCELLTIME_H_ */
