/*
 * BehBoundTime.cpp
 */

#include "BehBoundTime.h"
#include "../../../CHSM/values/ValueDouble.h"
#include "../../../Machine.h"

BehBoundTime::BehBoundTime() {}

void BehBoundTime::createVariables(Machine* machine, Holon* holon) 
{
  machine->createVariable("TimeStep", new ValueDouble(), holon);
}

void BehBoundTime::createVariables(
  Machine* machine, 
  Holon* holon, 
  double initTimeStep
) 
{
  machine->createVariable("TimeStep", new ValueDouble(initTimeStep), holon);
}
