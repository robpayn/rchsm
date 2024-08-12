/*
 * Matrix.h
 */

#ifndef CHSM_MATRIX_H_
#define CHSM_MATRIX_H_

#include "CHSM/values/ValueVarmap.h"
#include "CHSM/Dynamic.h"
#include <list>
#include "CHSM/DepManager.h"

class Matrix : public ValueVarmap, public Dynamic
{
  public:
    
    Dynamic* time_ = nullptr;
    
    DepManager* dm_ = nullptr;
    
    Matrix();
    
    virtual ~Matrix();
    
    void regDynamic(Dynamic*);
    
    void setDependencies(DepManager*) override;
    
    void setTime(Dynamic* time);
    
    void update() override;
};

#endif /* CHSM_MATRIX_H_ */
