/*
 * TimeValid.cpp
 */

#include "TimeValid.h"
#include "../../../CHSM/Holon.h"
#include "../../../CHSM/DepManager.h"
#include "../../../CHSM/values/ValueDouble.h"

TimeValid::TimeValid(bool initValue, int phase) :
  ValueBoolean(initValue)
{
  attachUpdater(new TimeValidUpdater(phase));
}

TimeValidUpdater::TimeValidUpdater(int phase) :
  Updater(phase)
{}

void TimeValidUpdater::setDependencies(DepManager& dm) 
{
  v_ = &(static_cast<ValueBoolean*>(val_)->v_);  
  
  time_ = &(
    dm.setDependency<ValueDouble>(val_, val_->var_->holon_, "Time")->v_
  );
  timeMax_ = &(
    dm.setDependency<ValueDouble>(val_, val_->var_->holon_, "TimeMax")->v_
  );
}

void TimeValidUpdater::update() 
{
  *v_ = *time_ < *timeMax_; 
}


