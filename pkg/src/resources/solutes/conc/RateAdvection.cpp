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
  RateDouble(initValue, -initValue, stateName, phase),
  velocityName_(velocityName)
{}

void RateAdvection::setDependencies(DepManager& dm)
{
  velocity_ = &(
    dm.setDependency<ValueDouble>(this, var_->holon_, velocityName_)->v_
  );
  
  length_ = &(
    dm.setDependency<ValueDouble>(this, var_->holon_, "length")->v_
  );
  
  Cell* cell = static_cast<Bound*>(var_->holon_)->cellTo_;
  if(!cell) {
    std::ostringstream error;
    error << "Cell must be attached on the to side of bound "
      << var_->holon_->name_ << " containing dynamic value RateAdvection.";
    throw std::runtime_error(error.str());
  }
  concTo_ = &(
    dm.setDependency<ValueDouble>(this, cell, stateName_)->v_
  );

  cell = static_cast<Bound*>(var_->holon_)->cellFrom_;
  if(!cell) {
    std::ostringstream error;
    error << "Cell must be attached on the from side of bound "
      << var_->holon_->name_ << " containing dynamic value RateAdvection.";
    throw std::runtime_error(error.str());
  }
  concFrom_ = &(
    dm.setDependency<ValueDouble>(this, cell, stateName_)->v_
  );
}

void RateAdvection::update()
{
  v_ = *velocity_ * ((*concFrom_ - *concTo_) / *length_);
  vf_ = -v_;
}
