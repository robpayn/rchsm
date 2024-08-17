/*
 * StateDouble.cpp
 */

#include "StateDouble.h"
#include "../Holon.h"
#include "../DepManager.h"
#include <sstream>

StateDouble::StateDouble(int phase) :
  ValueDoubleMemory(phase)
{}

StateDouble::StateDouble(int phase, double initValue) :
  ValueDoubleMemory(phase, initValue)
{}

void StateDouble::attachRate(ValueDouble* bound)
{
  
  rates_.push_back(&(bound->v_));
  
}

void StateDouble::setDependencies(DepManager* dm)
{
  
  Holon* timeBound = static_cast <Holon*> (
    var_->holon_->holon_->getVariable("BoundTime")
  );
  dt_ = &(
    dm->setDependency<ValueDouble>(this, timeBound, "TimeStep")->v_
  );

}

std::string StateDouble::toString()
{
  
  std::ostringstream string;
  
  string << "<State rates=\"";
  bool first = true;
  for(double* rate : rates_) {
    if (first) {
      first = false;
    } else {
      string << ",";
    }
    string << std::to_string(*rate);
  }
  string << "\">";
  
  string << ValueDouble::toString();
  
  string << "</State>";
  
  return string.str();
  
}

void StateDouble::update()
{
  
  double netRate = 0;
  for(double* rate : rates_) {
    netRate += *rate;
  }
  v_ += netRate * *dt_;
  
}
