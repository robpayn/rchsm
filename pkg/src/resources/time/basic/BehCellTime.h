/*
 * BehCellTime.h
 */

#ifndef RCHSM_TIME_BEHAVIOR_CELL_H_
#define RCHSM_TIME_BEHAVIOR_CELL_H_

#include "../../../CHSM/Behavior.h"
#include "Time.h"
#include "Iteration.h"

class BehCellTime : public Behavior
{
  public:
    // Constructors/Destructor
    
    BehCellTime();

    // Methods
    
    void createVariables(Holon* holon) override;
};

#endif /* RCHSM_TIME_BEHAVIOR_CELL_H_ */
