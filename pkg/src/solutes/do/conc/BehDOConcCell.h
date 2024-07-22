/*
 * BehDOConcCell.h
 */

#ifndef RCHSM_SOLUTES_DO_CONC_BEHAVIOR_CELL_H_
#define RCHSM_SOLUTES_DO_CONC_BEHAVIOR_CELL_H_

#include "../../../CHSM/Behavior.h"

class BehDOConcCell : virtual public Behavior
{
  public:
    // Constructors/Destructor
    
    BehDOConcCell();
    virtual ~BehDOConcCell() {};
    
    // Methods
    
    void createVariables(Holon* holon) override;
};

#endif /* RCHSM_SOLUTES_DO_CONC_BEHAVIOR_CELL_H_ */
