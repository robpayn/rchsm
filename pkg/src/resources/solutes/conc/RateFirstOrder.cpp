/*
 * RateFirstOrder.cpp
 */

#include "RateFirstOrder.h"
#include "../../../CHSM/Holon.h"
#include "../../../CHSM/Bound.h"
#include "../../../CHSM/Cell.h"
#include "../../../CHSM/DepManager.h"

RateFirstOrder::RateFirstOrder(
  double initValue, 
  std::string stateName, 
  std::string coeffName,
  int phase
) :
  RateDouble(initValue, 0, stateName, phase),
  coeffName_(coeffName)
{}

void RateFirstOrder::setDependencies(DepManager& dm)
{
  rateCoeff_ = &(
    dm.setDependency<ValueDouble>(this, var_->holon_, coeffName_)->v_
  );
  
  Cell* cell = static_cast<Bound*>(var_->holon_)->cellTo_;
  if(!cell) {
    std::ostringstream error;
    error << "Cell must be attached on the to side of bound "
      << var_->holon_->name_ << " containing dynamic value RateFirstOrder.";
    throw std::runtime_error(error.str());
  }
  conc_ = &(
    dm.setDependency<ValueDouble>(this, cell, stateName_)->v_
  );
}

void RateFirstOrder::update()
{
  v_ = -*rateCoeff_ * *conc_;
}