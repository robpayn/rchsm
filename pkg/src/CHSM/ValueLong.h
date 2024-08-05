/*
 * ValueLong.h
 */

#ifndef RCHSM_VALUELONG_H_
#define RCHSM_VALUELONG_H_

#include "Value.h"
#include "climits"
#include "cmath"

class ValueLong : public Value
{
  public:
    // Attributes
    
    long int_ = LONG_MIN;
    
    // Constructors
    
    ValueLong();
    
    ValueLong(long);
    
    ValueLong(std::string);
    
    // Methods
    
    void fromString(std::string valueString) override;
  
    std::string toString() override;
};

#endif /* RCHSM_VALUELONG_H_ */
