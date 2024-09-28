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
  RateDouble(initValue, -initValue, stateName)
{
  attachUpdater(new RateDispersionUpdater(coeffName, phase));
}

RateDispersionUpdater::RateDispersionUpdater(
  std::string coeffName,
  int phase
) :
  Updater(phase),
  coeffName_(coeffName)
{}

void RateDispersionUpdater::setDependencies(DepManager& dm)
{
  RateDouble* rate = static_cast<RateDouble*>(val_);
  
  v_ = &(rate->v_);  
  vf_ = &(rate->vf_);
  
  dispCoeff_ = &(
    dm.setDependency<ValueDouble>(rate, rate->var_->holon_, coeffName_)->v_
  );
  
  length_ = &(
    dm.setDependency<ValueDouble>(rate, rate->var_->holon_, "SpaceLength")->v_
  );
  
  Cell* cell = static_cast<Bound*>(rate->var_->holon_)->cellTo_;
  if(!cell) {
    std::ostringstream error;
    error << "Cell must be attached on the to side of bound "
      << rate->var_->holon_->name_ 
      << " containing dynamic value RateDispersion.";
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
      << " containing dynamic value RateDispersion.";
    throw std::runtime_error(error.str());
  }
  concFrom_ = &(
    dm.setDependency<ValueDouble>(rate, cell, rate->stateName_)->v_
  );
}

void RateDispersionUpdater::update()
{
  *v_ = *dispCoeff_ * ((*concFrom_ - *concTo_) / pow(*length_, 2));
  *vf_ = -*v_;
}
