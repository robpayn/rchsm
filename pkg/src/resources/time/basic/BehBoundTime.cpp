/*
 * BehBoundTime.cpp
 */

#include "BehBoundTime.h"
#include "TimeStep.h"
#include "../../../Machine.h"

BehBoundTime::BehBoundTime() {}

void BehBoundTime::createVariables(Machine* machine, Holon* holon) 
{
  Variable* variable = new Variable("TimeStep", new TimeStep());
  machine->installVariable(variable, holon);
}
