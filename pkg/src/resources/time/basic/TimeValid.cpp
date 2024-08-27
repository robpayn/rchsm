/*
 * TimeValid.cpp
 */

#include "TimeValid.h"
#include "../../../CHSM/Holon.h"
#include "../../../CHSM/DepManager.h"
#include "../../../CHSM/values/ValueDouble.h"

TimeValid::TimeValid(int phase) :
  ValueBooleanMemory(phase)
{}

TimeValid::TimeValid(int phase, bool init) :
  ValueBooleanMemory(phase, init)
{}

void TimeValid::setDependencies(DepManager& dm) 
{
  time_ = &(
    dm.setDependency<ValueDouble>(this, var_->holon_, "Time")->v_
  );
  timeMax_ = &(
    dm.setDependency<ValueDouble>(this, var_->holon_, "TimeMax")->v_
  );
}

void TimeValid::update() 
{
  
  v_ = *time_ < *timeMax_; 
  
}
