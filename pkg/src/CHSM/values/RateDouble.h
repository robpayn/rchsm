/*
 * RateDouble.h
 */

#ifndef CHSM_VALUES_RATEDOUBLE_H_
#define CHSM_VALUES_RATEDOUBLE_H_

#include "ValueDoubleMemory.h"
#include "../Rate.h"

class RateDouble : public ValueDoubleMemory, public Rate
{
  public:
    
    std::string stateName_;
    
    RateDouble(int, std::string);
    
    RateDouble(int, double, std::string);
    
    void attachStates() override;
    
};

#endif /* CHSM_VALUES_RATEDOUBLE_H_ */
