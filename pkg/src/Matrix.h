/*
 * Matrix.h
 */

#ifndef RCHSM_MATRIX_H_
#define RCHSM_MATRIX_H_

#include "CHSM/values/ValueVarmap.h"
#include "CHSM/Dynamic.h"

class Matrix : public ValueVarmap, public Dynamic
{
  public:
    Matrix();
    
    void setDependencies() override;
    
    void update() override;
};

#endif /* RCHSM_MATRIX_H_ */
