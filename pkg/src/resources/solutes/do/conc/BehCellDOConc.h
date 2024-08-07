/*
 * BehCellDOConc.h
 */

#ifndef CHSM_RESOURCES_SOLUTES_DO_CONC_BEHCELLDOCONC_H_
#define CHSM_RESOURCES_SOLUTES_DO_CONC_BEHCELLDOCONC_H_

#include "../../../../CHSM/Behavior.h"

class BehCellDOConc : public Behavior
{
  public:
    // Constructors/Destructor
    
    BehCellDOConc();
    virtual ~BehCellDOConc() {};
    
    // Methods
    
    void createVariables(Machine*, Holon*) override;
};

#endif /* CHSM_RESOURCES_SOLUTES_DO_CONC_BEHCELLDOCONC_H_ */
