/*
 * Variable.h
 */

#ifndef RCHSM_VARIABLE_H_
#define RCHSM_VARIABLE_H_

#include <string>
#include <sstream>
#include "Value.h"

class Holon;

class Variable
{
  public:
    // Attributes
    
    std::string name_ = "";
    
    Value* value_ = nullptr;
    
    Holon* holon_ = nullptr;
    
    // Constructors/Destructor
    
    Variable(std::string name);
    
    virtual ~Variable();
    
    // Methods
    
    void setHolon(Holon* holon);
    
    template <class T_VALUE>
    T_VALUE* getValue()
    {
      T_VALUE* valuePointer = dynamic_cast <T_VALUE*> (value_);
      if (valuePointer != nullptr) {
        return valuePointer;
      } else {
        std::ostringstream error;
        error << "Type requested is not valid for the value in variable" << name_;
        throw error.str();
      }
    }
    
    // void setValueFromString(std::string stringValue);
    // std::string getValueAsString();
};

#endif /* RCHSM_VARIABLE_H_ */
