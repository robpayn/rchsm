/*
 * BehCellTime.cpp
 */

#include "BehCellTime.h"
#include "Time.h"
#include "Iteration.h"
#include "../../../Machine.h"

BehCellTime::BehCellTime() {}

void BehCellTime::createVariables(Machine* machine, Holon* holon) 
{
  Variable* variable = new Variable("Time", new Time());
  machine->installVariable(variable, holon);

  variable = new Variable("Iteration", new Iteration());
  machine->installVariable(variable, holon);
}
