/*
 * Time.cpp
 */

#include "Time.h"
#include "../../../CHSM/Cell.h"
#include "../../../CHSM/DepManager.h"
#include "../../../CHSM/values/ValueDouble.h"
#include <unordered_map>

Time::Time(double initValue, int phase) :
  ValueDouble(initValue)
{
  attachUpdater(new TimeUpdater(phase));
}

TimeUpdater::TimeUpdater(int phase) :
  Updater(phase)
{}

void TimeUpdater::setDependencies(DepManager& dm) 
{
  v_ = &(static_cast<ValueDouble*>(val_)->v_);
  
  std::unordered_map<std::string, Variable*> boundVars = 
    static_cast <Cell*> (val_->var_->holon_)->getBoundVariables("TimeStep");
  if (boundVars.size() > 1) {
    throw std::runtime_error(
        std::string("More than one time step variable found ") +
          "in bounds attached to the time cell.\n"
    );
  } else if (boundVars.size() == 0) {
    throw std::runtime_error(
        "No time step variables found in bounds attached to the time cell.\n"
    );
  }
  
  timeStep_ = &(
    dm.setDependency<ValueDouble>(val_, boundVars.begin()->second)->v_
  );
  
}

void TimeUpdater::update() 
{
  *v_ += *timeStep_;
}
