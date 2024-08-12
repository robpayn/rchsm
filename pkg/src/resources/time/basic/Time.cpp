/*
 * Time.cpp
 */

#include "Time.h"
#include "../../../CHSM/DepManager.h"

#include "../../../CHSM/values/ValueBoolean.h"

Time::Time(int phase) :
  ValueDouble(),
  Dynamic(phase)
{}

Time::Time(int phase, double init) :
  ValueDouble(init),
  Dynamic(phase)
{}

void Time::setDependencies(DepManager* dm) 
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

  std::unordered_map<std::string, Variable*>::iterator iter = boundVars.begin();

  timeStep_ = &(dm->setDependency<ValueDouble>(this, iter->second)->v_);
  
  Variable* variable = var_->holon_->getVariable("Iteration");
  if (!variable) {
    throw std::runtime_error(
      "No iteration variable found in the time cell.\n"
    );
  }
  iteration_ = dynamic_cast <Dynamic*> (variable->value_);
  iteration_->setDependencies(dm);
  
  variable = var_->holon_->getVariable("TimeValid");
  if (!variable) {
    throw std::runtime_error(
      "No time valid variable found in the time cell.\n"
    );
  }
  timeValid_ = dynamic_cast <Dynamic*> (variable->value_);
  timeValid_->setDependencies(dm);
  
}

void Time::update() {
  
  v_ = v_ + *timeStep_;
  timeValid_->update();
  iteration_->update();
  
}
