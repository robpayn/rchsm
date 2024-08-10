/*
 * ValueLong.h
 */

#ifndef CHSM_VALUES_VALUELONG_H_
#define CHSM_VALUES_VALUELONG_H_

#include "../Value.h"
#include <climits>
#include <cmath>

class ValueLong : public Value
{
  public:
    // Attributes
    
    long v_ = LONG_MIN;
    
    // Constructors
    
    ValueLong();
    
    ValueLong(long);
    
    ValueLong(std::string);
    
    // Methods
    
    void fromString(std::string valueString) override;
    
    bool isDefined() override;
  
    std::string toString() override;
};

#endif /* CHSM_VALUES_VALUELONG_H_ */
