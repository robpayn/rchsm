/*
 * Matrix.h
 */

#ifndef CHSM_MATRIX_H_
#define CHSM_MATRIX_H_

#include "CHSM/values/ValueVarmap.h"
#include "CHSM/Dynamic.h"
#include "CHSM/DepManager.h"
#include "CHSM/Solver.h"
#include <vector>

class Matrix : public ValueVarmap, public Dynamic
{
  public:
    
    DepManager* dm_ = nullptr;
    
    Solver* solver_ = nullptr;
    
    Matrix();
    
    virtual ~Matrix();
    
    void regDynamic(Dynamic*);
    
    void setDependencies(DepManager*) override;
    
    void update() override;
    
};

#endif /* CHSM_MATRIX_H_ */
