/*
 * StateDouble.cpp
 */

#include "StateDouble.h"
#include "RateDouble.h"
#include "../Holon.h"
#include "../DepManager.h"
#include <sstream>

StateDouble::StateDouble(
  double initValue,
  int phase, 
  std::shared_ptr<MemoryFactory> mf
) :
  ValueDoubleMemory(initValue, phase, mf)
{}

void StateDouble::attachRate(double* rate)
{
  rates_.push_back(rate);
}

void StateDouble::setDependencies(DepManager& dm)
{
  Holon* timeBound = static_cast <Holon*> (
    var_->holon_->holon_->getVariable("BoundTime")
  );
  dt_ = &(
    dm.setDependency<ValueDouble>(this, timeBound, "TimeStep")->v_
  );
}

void StateDouble::update()
{
  double netRate = 0;
  for(double* rate : rates_) {
    netRate += *rate;
  }
  v_ += netRate * *dt_;
}
