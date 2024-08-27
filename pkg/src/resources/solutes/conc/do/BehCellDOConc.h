/*
 * BehCellDOConc.h
 */

#ifndef CHSM_RESOURCES_SOLUTES_CONC_DO_BEHCELLDOCONC_H_
#define CHSM_RESOURCES_SOLUTES_CONC_DO_BEHCELLDOCONC_H_

class Matrix;
class Holon;

class BehCellDOConc
{
  public:
    // Constructors/Destructor
    
    BehCellDOConc();
    virtual ~BehCellDOConc() {};
    
    // Methods
    
    void createVariables(Matrix*, Holon&, double);
    
};

#endif /* CHSM_RESOURCES_SOLUTES_CONC_DO_BEHCELLDOCONC_H_ */
