/*
 * Time.cpp
 */

#include "Time.h"

Time::Time() :
  ValueDouble()
{
  phase_ = 0;
}

Time::Time(double init) :
  ValueDouble(init)
{
  phase_ = 0;
}

void Time::setDependencies() 
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

  ValueDouble* value = iter->second->getValue<ValueDouble>();
  timeStep_ = &(value->real_);

  Variable* variable = var_->holon_->getVariable("Iteration");
  if (variable) {
    iteration_ = dynamic_cast <Dynamic*> (variable->value_);
  } else {
    throw std::runtime_error("No iteration variable found in the time cell.\n");
  }
}

void Time::update() {
  
  real_ = real_ + *timeStep_;
  iteration_->update();
  
}
