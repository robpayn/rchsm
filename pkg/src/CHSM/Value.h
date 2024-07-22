/*
 * Value.h
 */

#ifndef RCHSM_VALUE_H_
#define RCHSM_VALUE_H_

#include <string>

class Value
{
  public:
    // Constructors/Destructor
    
    Value();
    
    virtual ~Value();
    
    // Methods
    
    virtual void fromString(std::string valueString) = 0;
    
    virtual std::string toString() = 0;
};

#endif /* RCHSM_VALUE_H_ */