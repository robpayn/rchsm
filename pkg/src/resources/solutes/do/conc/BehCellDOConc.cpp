/*
 * BehCellDOConc.cpp
 */

#include "BehCellDOConc.h"
#include "StateDOConc.h"
#include "../../../../Machine.h"

BehCellDOConc::BehCellDOConc() {};

void BehCellDOConc::createVariables(Machine* machine, Holon* holon) {
  int phase = 1;
  machine->createVariable("DOConc", new StateDOConc(phase), holon);
}
