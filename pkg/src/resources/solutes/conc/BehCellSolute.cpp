/*
 * BehCellSolute.cpp
 */

#include "BehCellSolute.h"
#include "../../../Machine.h"
#include "../../../CHSM/values/StateDouble.h"

BehCellSolute::BehCellSolute(std::string soluteName) :
  soluteName_(soluteName)
{
  setNames();
}

void BehCellSolute::createVariables(Machine* machine, Holon* holon) {
  int phase = 2;
  machine->createVariable(stateName_, new StateDouble(phase), holon);
}

void BehCellSolute::createVariables(
  Machine* machine, 
  Holon* holon, 
  double initValue
) 
{
  int phase = 2;
  machine->createVariable(
    stateName_, 
    new StateDouble(phase, initValue), 
    holon
  );
}

void BehCellSolute::setNames()
{
  stateName_ = soluteName_ + stateSuffix_;
}
