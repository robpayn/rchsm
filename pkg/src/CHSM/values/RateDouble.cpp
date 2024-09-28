/*
 * RateDouble.cpp
 */

#include "RateDouble.h"
#include "StateDouble.h"
#include "../Cell.h"
#include "../Bound.h"
#include "../Updater.h"

RateDouble::RateDouble(
  double initValue,
  double initValueFrom,
  std::string stateName
) :
  ValueDouble(initValue),
  vf_(initValueFrom),
  stateName_(stateName)
{}

void RateDouble::attachStates()
{
  
  Bound* bound = dynamic_cast<Bound*>(var_->holon_);
  if (!bound) {
    std::ostringstream error;
    error << "Rate variable " << var_->name_ << " is not "
      << "installed in a bound. Cannot attach states in adjacents cells.";
    throw std::runtime_error(error.str());
  }
  
  if(bound->cellFrom_) {
    StateDouble* state = bound->cellFrom_->getVarValue<StateDouble>(stateName_);
    if (state) {
      state->attachRate(&vf_);
    }
  }
  if(bound->cellTo_) {
    StateDouble* state = bound->cellTo_->getVarValue<StateDouble>(stateName_);
    if (state) {
      state->attachRate(&v_);
    }
  }
  
}
