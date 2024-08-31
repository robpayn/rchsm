/*
 * TimeValid.h
 */

#ifndef RESOURCES_TIME_BASIC_TIMEVALID_H_
#define RESOURCES_TIME_BASIC_TIMEVALID_H_

#include "../../../CHSM/values/ValueBooleanMemory.h"

class TimeValid : public ValueBooleanMemory
{
public:
  
  double* time_ = nullptr;
  
  double* timeMax_ = nullptr;
  
  // Constructors/Destructor
  
  TimeValid(bool, int, std::shared_ptr<MemoryFactory> = nullptr);
  
  // Methods
  
  void setDependencies(DepManager&) override;
  
  void update() override;
};

#endif /* RESOURCES_TIME_BASIC_TIMEVALID_H_ */
