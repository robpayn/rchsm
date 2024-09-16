/*
 * TimeValid.cpp
 */

#include "TimeValid.h"
#include "../../../CHSM/Holon.h"
#include "../../../CHSM/DepManager.h"
#include "../../../CHSM/values/ValueDouble.h"

TimeValid::TimeValid(
  bool init, 
  int phase
) :
  ValueBoolean(init),
  DynamicMemory(phase)
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
