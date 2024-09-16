/*
 * Time.cpp
 */

#include "Time.h"
#include "../../../CHSM/Cell.h"
#include "../../../CHSM/DepManager.h"
#include <unordered_map>

Time::Time(
  double init, 
  int phase
) :
  ValueDouble(init),
  DynamicMemory(phase)
{}

void Time::setDependencies(DepManager& dm) 
{
  
  std::unordered_map<std::string, Variable*> boundVars = 
    static_cast <Cell*> (var_->holon_)->getBoundVariables("TimeStep");
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
    dm.setDependency<ValueDouble>(this, boundVars.begin()->second)->v_
  );
  
}

void Time::update() {
  
  v_ = v_ + *timeStep_;

}
