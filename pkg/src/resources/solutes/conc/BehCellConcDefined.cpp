/*
 * BehCellConcDefined.cpp
 */

#include "BehCellConcDefined.h"
#include "../../../Matrix.h"
#include "../../../CHSM/values/StateDoubleDefined.h"
#include "../../../CHSM/values/MemoryDoubleFactory.h"

BehCellConcDefined::BehCellConcDefined(
  std::string soluteName
) :
  soluteName_(soluteName)
{
  setNames();
}

void BehCellConcDefined::createVariables(
  Matrix* matrix, 
  Holon& holon,
  Holon& timeHolon,
  std::string timeStepName,
  std::string iterationName,
  std::vector<double> values,
  MemoryDoubleFactory* mf
) 
{
  int phase = 2;
  Value* val = new StateDoubleDefined(
    timeHolon, 
    timeStepName, 
    iterationName, 
    values, 
    phase
  );
  if(mf) {
    mf->createMemory(val);
  }
  matrix->createVariable(stateName_, val, holon);
}

void BehCellConcDefined::setNames()
{
  stateName_ = soluteName_ + stateSuffix_;
}
