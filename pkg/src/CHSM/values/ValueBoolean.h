/**
 * ValueBoolean.cpp
 */

#ifndef CHSM_VALUES_VALUEBOOLEAN_H_
#define CHSM_VALUES_VALUEBOOLEAN_H_

#include "ValueBoolean.h"
#include "../Value.h"

class ValueBoolean : public Value
{
public:
  // Attributes
  
  bool v_ = false;
  
  bool isDefined_ = false;
  
  // Constructors
  
  ValueBoolean();
  
  ValueBoolean(bool);
  
  ValueBoolean(std::string);
  
  // Methods
  
  void fromString(std::string valueString) override;
  
  bool isDefined() override;
  
  void setValue(bool);
  
  std::string toString() override;
};

#endif /* CHSM_VALUES_VALUEBOOLEAN_H_ */
