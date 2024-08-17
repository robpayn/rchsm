/*
 * StateDouble.h
 */

#ifndef CHSM_VALUES_STATEDOUBLE_H_
#define CHSM_VALUES_STATEDOUBLE_H_

#include "ValueDoubleMemory.h"
#include <list>

class Bound;

class StateDouble : public ValueDoubleMemory
{
  public:
    
    std::list<double*> rates_;
    
    double* dt_ = nullptr;
    
    StateDouble(int);
    
    StateDouble(int, double);
    
    void attachRate(ValueDouble*);
    
    void setDependencies(DepManager*) override;
    
    std::string toString() override;
    
    void update() override;
    
};

#endif /* CHSM_VALUES_STATEDOUBLE_H_ */
