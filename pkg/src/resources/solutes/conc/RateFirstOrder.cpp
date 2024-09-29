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
  RateDouble(initValue, 0, stateName)
{
  attachUpdater(new RateFirstOrderUpdater(coeffName, phase));
}

RateFirstOrderUpdater::RateFirstOrderUpdater(
  std::string coeffName,
  int phase
) :
  UpdaterDouble(phase),
  coeffName_(coeffName)
{}

void RateFirstOrderUpdater::setDependencies(DepManager& dm)
{
  RateDouble* rate = static_cast<RateDouble*>(val_);
  
  rateCoeff_ = &(
    dm.setDependency<ValueDouble>(rate, rate->var_->holon_, coeffName_)->v_
  );
  
  Cell* cell = static_cast<Bound*>(rate->var_->holon_)->cellTo_;
  if(!cell) {
    std::ostringstream error;
    error << "Cell must be attached on the to side of bound "
      << rate->var_->holon_->name_ 
      << " containing dynamic value RateFirstOrder.";
    throw std::runtime_error(error.str());
  }
  conc_ = &(
    dm.setDependency<ValueDouble>(rate, cell, rate->stateName_)->v_
  );
}

void RateFirstOrderUpdater::update()
{
  *v_ = -*rateCoeff_ * *conc_;
}