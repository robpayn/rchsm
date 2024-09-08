/*
 * RateDispersion.cpp
 */

#include "RateDispersion.h"
#include "../../../CHSM/DepManager.h"
#include "../../../CHSM/Cell.h"
#include "../../../CHSM/Bound.h"

RateDispersion::RateDispersion(
  double initValue, 
  std::string stateName, 
  std::string coeffName,
  int phase
) :
  RateDouble(initValue, -initValue, stateName, phase),
  coeffName_(coeffName)
{}

void RateDispersion::setDependencies(DepManager& dm)
{
  dispCoeff_ = &(
    dm.setDependency<ValueDouble>(this, var_->holon_, coeffName_)->v_
  );
  
  length_ = &(
    dm.setDependency<ValueDouble>(this, var_->holon_, "length")->v_
  );
  
  Cell* cell = static_cast<Bound*>(var_->holon_)->cellTo_;
  if(!cell) {
    std::ostringstream error;
    error << "Cell must be attached on the to side of bound "
      << var_->holon_->name_ << " containing dynamic value RateDispersion.";
    throw std::runtime_error(error.str());
  }
  concTo_ = &(
    dm.setDependency<ValueDouble>(this, cell, stateName_)->v_
  );

  cell = static_cast<Bound*>(var_->holon_)->cellFrom_;
  if(!cell) {
    std::ostringstream error;
    error << "Cell must be attached on the from side of bound "
      << var_->holon_->name_ << " containing dynamic value RateDispersion.";
    throw std::runtime_error(error.str());
  }
  concFrom_ = &(
    dm.setDependency<ValueDouble>(this, cell, stateName_)->v_
  );
}

void RateDispersion::update()
{
  v_ = *dispCoeff_ * ((*concFrom_ - *concTo_) / pow(*length_, 2));
  vf_ = -v_;
}
