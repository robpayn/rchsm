/*
 * RateAdvection.cpp
 */

#include "RateAdvection.h"
#include "../../../CHSM/DepManager.h"
#include "../../../CHSM/Cell.h"
#include "../../../CHSM/Bound.h"

RateAdvection::RateAdvection(
  double initValue, 
  std::string stateName, 
  std::string velocityName,
  int phase
) :
  RateDouble(initValue, initValue, stateName)
{
  attachUpdater(new RateAdvectionUpdater(velocityName, phase));
}

RateAdvectionUpdater::RateAdvectionUpdater(
  std::string velocityName,
  int phase
) :
  Updater(phase),
  velocityName_(velocityName)
{}

void RateAdvectionUpdater::setDependencies(DepManager& dm)
{
  RateDouble* rate = static_cast<RateDouble*>(val_);
  
  v_ = &(rate->v_);  
  vf_ = &(rate->vf_);  
  
  velocity_ = &(
    dm.setDependency<ValueDouble>(rate, rate->var_->holon_, velocityName_)->v_
  );
  
  length_ = &(
    dm.setDependency<ValueDouble>(rate, rate->var_->holon_, "SpaceLength")->v_
  );
  
  Cell* cell = static_cast<Bound*>(rate->var_->holon_)->cellTo_;
  if(!cell) {
    std::ostringstream error;
    error << "Cell must be attached on the to side of bound "
      << rate->var_->holon_->name_ \
      << " containing dynamic value RateAdvection.";
    throw std::runtime_error(error.str());
  }
  concTo_ = &(
    dm.setDependency<ValueDouble>(rate, cell, rate->stateName_)->v_
  );

  cell = static_cast<Bound*>(rate->var_->holon_)->cellFrom_;
  if(!cell) {
    std::ostringstream error;
    error << "Cell must be attached on the from side of bound "
      << rate->var_->holon_->name_ 
      << " containing dynamic value RateAdvection.";
    throw std::runtime_error(error.str());
  }
  concFrom_ = &(
    dm.setDependency<ValueDouble>(rate, cell, rate->stateName_)->v_
  );
}

void RateAdvectionUpdater::update()
{
  *v_ = *velocity_ * ((*concFrom_ - *concTo_) / (2 * *length_));
  *vf_ = *v_;
}
