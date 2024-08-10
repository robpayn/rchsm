/*
 * Matrix.h
 */

#ifndef CHSM_MATRIX_H_
#define CHSM_MATRIX_H_

#include "CHSM/values/ValueVarmap.h"
#include "CHSM/Dynamic.h"

class Matrix : public ValueVarmap, public Dynamic
{
  public:
    Dynamic* time_ = nullptr;
    
    Matrix();
    
    void setDependencies() override;
    
    void setTime(Dynamic* time);
    
    void update() override;
};

#endif /* CHSM_MATRIX_H_ */
