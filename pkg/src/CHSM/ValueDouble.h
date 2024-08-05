/*
 * ValueDouble.h
 */

#ifndef RCHSM_VALUEDOUBLE_H_
#define RCHSM_VALUEDOUBLE_H_

#include "Value.h"
#include <cmath>

class ValueDouble : public Value
{
  public:
    // Attributes
    
    double real_ = nan("");
    
    // Constructors
    
    ValueDouble();
    
    ValueDouble(double);
    
    ValueDouble(std::string valueString);
    
    // Methods
    
    void fromString(std::string valueString) override;
  
    std::string toString() override;
};

#endif /* RCHSM_VALUEDOUBLE_H_ */
