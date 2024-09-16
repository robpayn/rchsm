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
  int phase
) :
  ValueDouble(initValue),
  DynamicMemory(phase),
  dt_(&(timeHolon.getVarValue<ValueDouble>(timeStepName)->v_))
{}

void StateDouble::attachRate(double* rate)
{
  rates_.push_back(rate);
}

void StateDouble::setDependencies(DepManager& dm)
{}

void StateDouble::update()
{
  double netRate = 0;
  for(double* rate : rates_) {
    netRate += *rate;
  }
  v_ += netRate * *dt_;
}
