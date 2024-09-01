/*
 * BehCellSolute.cpp
 */

#include "BehCellSolute.h"
#include "../../../Matrix.h"
#include "../../../CHSM/values/StateDouble.h"
#include "../../../CHSM/values/MemoryDoubleFactory.h"

BehCellSolute::BehCellSolute(std::string soluteName) :
  soluteName_(soluteName)
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
      std::make_shared<MemoryDoubleFactory>(1)
    ), 
    holon
  );
}

void BehCellSolute::setNames()
{
  stateName_ = soluteName_ + stateSuffix_;
}
