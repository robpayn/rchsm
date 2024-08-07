/*
 * ValueDouble.h
 */

#ifndef CHSM_VALUES_VALUEDOUBLE_H_
#define CHSM_VALUES_VALUEDOUBLE_H_

#include "../Value.h"
#include <cmath>

class ValueDouble : public Value
{
  public:
    // Attributes
    
    double real_ = nan("");
    
    // Constructors
    
    ValueDouble();
    
    ValueDouble(double);
    
    ValueDouble(std::string);
    
    // Destructor
    
    virtual ~ValueDouble();
    
    // Methods
    
    void fromString(std::string) override;
    
    bool isDefined() override;
  
    std::string toString() override;
};

#endif /* CHSM_VALUES_VALUEDOUBLE_H_ */
