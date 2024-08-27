/*
 * RateDouble.cpp
 */

#include "RateDouble.h"
#include "StateDouble.h"
#include "../Cell.h"
#include "../Bound.h"

RateDouble::RateDouble(int phase, std::string stateName) :
  ValueDoubleMemory(phase),
  stateName_(stateName)
{}

RateDouble::RateDouble(int phase, double initValue, std::string stateName) :
  ValueDoubleMemory(phase, initValue),
  vf_(-initValue),
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