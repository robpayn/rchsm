/*
 * RateFirstOrder.cpp
 */

#include "RateFirstOrder.h"
#include "../../../CHSM/Holon.h"
#include "../../../CHSM/Bound.h"
#include "../../../CHSM/Cell.h"
#include "../../../CHSM/DepManager.h"

RateFirstOrder::RateFirstOrder(
  int phase, 
  std::string stateName, 
  std::string coeffName
) :
  RateDouble(phase, stateName),
  coeffName_(coeffName)
{}

RateFirstOrder::RateFirstOrder(
  int phase, 
  double initValue, 
  std::string stateName, 
  std::string coeffName
) :
  RateDouble(phase, initValue, stateName),
  coeffName_(coeffName)
{}

void RateFirstOrder::setDependencies(DepManager* dm)
{
  rateCoeff_ = &(
    dm->setDependency<ValueDouble>(this, var_->holon_, coeffName_)->v_
  );
  
  Cell* cell = static_cast<Bound*>(var_->holon_)->cellTo_;
  ValueDouble* state = dm->setDependency<ValueDouble>(this, cell, stateName_);
  conc_ = &(state->v_);
}

void RateFirstOrder::update()
{
  v_ = -*rateCoeff_ * *conc_;
}