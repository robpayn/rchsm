/*
 * TimeValid.cpp
 */

#include "TimeValid.h"
#include "../../../CHSM/Holon.h"
#include "../../../CHSM/values/ValueDouble.h"

TimeValid::TimeValid(int phase) :
  ValueBoolean(),
  Dynamic(phase)
{}

TimeValid::TimeValid(int phase, bool init) :
  ValueBoolean(init),
  Dynamic(phase)
{}

void TimeValid::setDependencies(DepManager* dm) 
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
