/*
 * TimeValid.h
 */

#ifndef RESOURCES_TIME_BASIC_TIMEVALID_H_
#define RESOURCES_TIME_BASIC_TIMEVALID_H_

#include "../../../CHSM/values/ValueBoolean.h"
#include "../../../CHSM/DynamicMemory.h"

class TimeValid : public ValueBoolean, public DynamicMemory
{
public:
  
  double* time_ = nullptr;
  
  double* timeMax_ = nullptr;
  
  // Constructors/Destructor
  
  TimeValid(bool, int);
  
  // Methods
  
  void setDependencies(DepManager&) override;
  
  void update() override;
};

#endif /* RESOURCES_TIME_BASIC_TIMEVALID_H_ */
