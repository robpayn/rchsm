/*
 * TimeValid.h
 */

#ifndef RESOURCES_TIME_BASIC_TIMEVALID_H_
#define RESOURCES_TIME_BASIC_TIMEVALID_H_

#include "../../../CHSM/values/ValueBoolean.h"
#include "../../../CHSM/Dynamic.h"

class TimeValid : public ValueBoolean, public Dynamic
{
public:
  
  double* time_ = nullptr;
  
  double* timeMax_ = nullptr;
  
  // Constructors/Destructor
  
  TimeValid(int);
  
  TimeValid(int, bool);
  
  // Methods
  
  void setDependencies() override;
  
  void update() override;
};

#endif /* RESOURCES_TIME_BASIC_TIMEVALID_H_ */
