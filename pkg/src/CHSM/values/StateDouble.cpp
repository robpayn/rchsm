/*
 * StateDouble.cpp
 */

#include "StateDouble.h"
#include "RateDouble.h"
#include "../Holon.h"
#include "../DepManager.h"

StateDouble::StateDouble(
  Holon& timeHolon,
  std::string timeStepName,
  double initValue,
  int phase,
  Updater* updater
) :
  ValueDouble(initValue)
{
  if(updater) {
    attachUpdater(updater);
  } else {
    attachUpdater(new StateDoubleUpdater(timeHolon, timeStepName, phase));
  }
}

void StateDouble::attachRate(double* rate)
{
  static_cast<StateDoubleUpdater*>(updater_)->attachRate(rate);
}

StateDoubleUpdater::StateDoubleUpdater(
  Holon& timeHolon, 
  std::string timeStepName,
  int phase
) :
  Updater(phase),
  dt_(&(timeHolon.getVarValue<ValueDouble>(timeStepName)->v_))
{}

void StateDoubleUpdater::setDependencies(DepManager& dm)
{
  v_ = &(static_cast<ValueDouble*>(val_)->v_);
}

void StateDoubleUpdater::attachRate(double* rate)
{
  rates_.push_back(rate);
}

void StateDoubleUpdater::update()
{
  double netRate = 0;
  for(double* rate : rates_) {
    netRate += *rate;
  }
  *v_ += netRate * *dt_;
}
