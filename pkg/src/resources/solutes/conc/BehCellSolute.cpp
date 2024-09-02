/*
 * BehCellSolute.cpp
 */

#include "BehCellSolute.h"
#include "../../../Matrix.h"
#include "../../../CHSM/values/StateDouble.h"
#include "../../../CHSM/values/MemoryDoubleFactory.h"

BehCellSolute::BehCellSolute(
  std::string soluteName, 
  std::shared_ptr<MemoryDoubleFactory> mfDouble
) :
  soluteName_(soluteName),
  mfDouble_(mfDouble)
{
  setNames();
}

void BehCellSolute::createVariables(
  Matrix* matrix, 
  Holon& holon, 
  double initValue
) 
{
  int phase = 2;
  matrix->createVariable(
    stateName_, 
    new StateDouble(
      initValue, 
      phase, 
      mfDouble_
    ), 
    holon
  );
}

void BehCellSolute::setNames()
{
  stateName_ = soluteName_ + stateSuffix_;
}
