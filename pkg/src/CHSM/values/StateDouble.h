/*
 * StateDouble.h
 */

#ifndef CHSM_VALUES_STATEDOUBLE_H_
#define CHSM_VALUES_STATEDOUBLE_H_

#include "ValueDouble.h"
#include "../Dynamic.h"

class StateDouble : public ValueDouble, public Dynamic
{
  public:
    
    double netRate_ = 0;
    
    double* dt_ = nullptr;
    
    StateDouble(int);
    
    StateDouble(int, double);
    
    void setDependencies(DepManager*) override;
    
    void update() override;
    
};

#endif /* CHSM_VALUES_STATEDOUBLE_H_ */
