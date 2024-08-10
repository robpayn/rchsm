/*
 * TimeValid.cpp
 */

#include "TimeValid.h"
#include "../../../CHSM/Holon.h"
#include "../../../CHSM/values/ValueDouble.h"

TimeValid::TimeValid() :
  ValueBoolean()
{
  phase_ = 0;
}

TimeValid::TimeValid(bool init) :
  ValueBoolean(init)
{
  phase_ = 0;
}

void TimeValid::setDependencies() 
{
  Variable* variable = var_->holon_->getVariable("Time");
  if (variable) {
    time_ = &(static_cast <ValueDouble*> (variable->value_)->v_);
  } else {
    throw std::runtime_error(
      "No time variable with name Time found in the time cell.\n"
    );
  }
  
  variable = var_->holon_->getVariable("TimeMax");
  if (variable) {
    timeMax_ = &(static_cast <ValueDouble*> (variable->value_)->v_);
  } else {
    throw std::runtime_error(
      "No maximum time variable with name TimeMax found in the time cell.\n"
    );
  }
  
}

void TimeValid::update() 
{
  
  v_ = *time_ <= *timeMax_; 
  
}
