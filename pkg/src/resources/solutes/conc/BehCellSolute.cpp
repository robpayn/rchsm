/*
 * BehCellSolute.cpp
 */

#include "BehCellSolute.h"
#include "../../../Matrix.h"
#include "../../../CHSM/values/StateDouble.h"
#include "../../../CHSM/values/MemoryDoubleFactory.h"

BehCellSolute::BehCellSolute(
  std::string soluteName
) :
  soluteName_(soluteName)
{
  setNames();
}

void BehCellSolute::createVariables(
  Matrix* matrix, 
  Holon& holon,
  Holon& timeHolon,
  std::string timeStepName,
  double initValue,
  MemoryDoubleFactory* mf
) 
{
  int phase = 2;
  Value* val = new StateDouble(timeHolon, timeStepName, initValue, phase);
  if(mf) {
    mf->createMemory(val);
  }
  matrix->createVariable(stateName_, val, holon);
}

void BehCellSolute::setNames()
{
  stateName_ = soluteName_ + stateSuffix_;
}
