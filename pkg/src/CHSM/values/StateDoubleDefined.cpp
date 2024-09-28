/*
 * StateDoubleDefined.cpp
 */

#include "StateDoubleDefined.h"
#include "../Bound.h"
#include "../Cell.h"
#include "ValueLong.h"

StateDoubleDefined::StateDoubleDefined(
  Holon& timeHolon,
  std::string timeStepName,
  std::string iterationName,
  std::vector<double> values, 
  int phase
) :
  StateDouble(
    timeHolon, 
    timeStepName, 
    values[0], 
    phase, 
    new StateDoubleDefinedUpdater(
      timeHolon, timeStepName, iterationName, values, phase
    )
  )
{}

StateDoubleDefinedUpdater::StateDoubleDefinedUpdater(
  Holon& timeHolon,
  std::string timeStepName,
  std::string iterationName,
  std::vector<double> values,
  int phase
) :
  StateDoubleUpdater(timeHolon, timeStepName, phase),
  values_(values),
  length_((long)values.size())
{
  Cell& timeCell = *(static_cast<Bound&>(timeHolon).cellTo_);
  iter_ = &(timeCell.getVarValue<ValueLong>(iterationName)->v_);
}

void StateDoubleDefinedUpdater::update()
{
  long index = *iter_ + 1;
  if (index < length_) {
    *v_ = values_[index];
  } else {
    *v_ = values_[length_ - 1];
  }
}
