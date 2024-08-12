/*
 * StateDouble.cpp
 */

#include "StateDouble.h"
#include "../Holon.h"
#include "../DepManager.h"

StateDouble::StateDouble(int phase) :
  ValueDouble(),
  Dynamic(phase)
{}

StateDouble::StateDouble(int phase, double initValue) :
  ValueDouble(initValue),
  Dynamic(phase)
{}

void StateDouble::setDependencies(DepManager* dm)
{
  
  Holon* timeBound = static_cast <Holon*> (
    var_->holon_->holon_->getVariable("BoundTime")
  );
  dt_ = &(
    dm->setDependency<ValueDouble>(this, timeBound, "TimeStep")->v_
  );

}

void StateDouble::update()
{
  
  v_ = v_ + netRate_ * *dt_;
  
}
