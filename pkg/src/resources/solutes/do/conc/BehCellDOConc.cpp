/*
 * BehCellDOConc.cpp
 */

#include "BehCellDOConc.h"
#include "StateDOConc.h"
#include "../../../../Machine.h"

BehCellDOConc::BehCellDOConc() {};

void BehCellDOConc::createVariables(Machine* machine, Holon* holon) {
  machine->createVariable("DOConc", new StateDOConc(), holon);
}
