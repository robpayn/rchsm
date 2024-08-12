/*
 * RateDouble.h
 */

#ifndef CHSM_VALUES_RATEDOUBLE_H_
#define CHSM_VALUES_RATEDOUBLE_H_

#include "ValueDouble.h"
#include "../Dynamic.h"

class RateDouble : public ValueDouble, public Dynamic
{
  public:
    
    RateDouble(int);
    
    RateDouble(int, double);
    
    void setDependencies(DepManager*) override;
    
    void update() override;
    
};

#endif /* CHSM_VALUES_RATEDOUBLE_H_ */
