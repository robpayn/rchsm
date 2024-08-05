/*
 * BehCellDOConc.cpp
 */

#include "BehCellDOConc.h"
#include "StateDOConc.h"

BehCellDOConc::BehCellDOConc() {};

void BehCellDOConc::createVariables(Holon* holon) {
  Variable* variable = new Variable("DOConc", new StateDOConc());
  holon->addVariable(variable);
}
