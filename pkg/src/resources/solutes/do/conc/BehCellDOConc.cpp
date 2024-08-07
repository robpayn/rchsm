/*
 * BehCellDOConc.cpp
 */

#include "BehCellDOConc.h"
#include "StateDOConc.h"
#include "../../../../Machine.h"

BehCellDOConc::BehCellDOConc() {};

void BehCellDOConc::createVariables(Machine* machine, Holon* holon) {
  Variable* variable = new Variable("DOConc", new StateDOConc());
  machine->installVariable(variable, holon);
}
