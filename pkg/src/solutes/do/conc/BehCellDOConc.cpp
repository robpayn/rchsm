/*
 * BehCellDOConc.cpp
 */

#include "BehCellDOConc.h"
#include "StateDOConc.h"
#include <string>
#include <iostream>

BehCellDOConc::BehCellDOConc() {};

void BehCellDOConc::createVariables(Holon* holon) {
  Variable* variable = new StateDOConc("DOConc");
  holon->addVariable(variable);
}
