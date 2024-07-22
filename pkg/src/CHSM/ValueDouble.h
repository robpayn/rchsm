/*
 * ValueDouble.h
 */

#ifndef RCHSM_VALUEDOUBLE_H_
#define RCHSM_VALUEDOUBLE_H_

#include <cmath>
#include "Value.h"

class ValueDouble : virtual public Value
{
  public:
    // Attributes
    
    double real_ = nan("");
    
    // Constructors/Destructor
    
    ValueDouble();
    
    ValueDouble(double value);
    
    ValueDouble(std::string valueString);
    
    // Methods
    
    void fromString(std::string valueString) override;
  
    std::string toString() override;
};

#endif /* RCHSM_VALUEDOUBLE_H_ */