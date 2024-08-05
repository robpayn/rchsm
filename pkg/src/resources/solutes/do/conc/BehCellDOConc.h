/*
 * BehCellDOConc.h
 */

#ifndef RCHSM_SOLUTES_DO_CONC_BEHAVIOR_CELL_H_
#define RCHSM_SOLUTES_DO_CONC_BEHAVIOR_CELL_H_

#include "../../../../CHSM/Behavior.h"

class BehCellDOConc : public Behavior
{
  public:
    // Constructors/Destructor
    
    BehCellDOConc();
    virtual ~BehCellDOConc() {};
    
    // Methods
    
    void createVariables(Holon* holon) override;
};

#endif /* RCHSM_SOLUTES_DO_CONC_BEHAVIOR_CELL_H_ */
