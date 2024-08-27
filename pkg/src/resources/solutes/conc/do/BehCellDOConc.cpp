/*
 * BehCellDOConc.cpp
 */

#include "BehCellDOConc.h"
#include "../../../../Matrix.h"
#include "StateDOConc.h"

BehCellDOConc::BehCellDOConc() {};

void BehCellDOConc::createVariables(
  Matrix* matrix, 
  Holon& holon, 
  double initDOConc
) 
{
  int phase = 2;
  matrix->createVariable(
    "DOConc", 
    new StateDOConc(phase, initDOConc), 
    holon
  );
}
