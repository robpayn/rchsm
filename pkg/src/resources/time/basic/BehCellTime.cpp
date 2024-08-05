/*
 * BehCellTime.cpp
 */

#include "BehCellTime.h"

BehCellTime::BehCellTime() {}

void BehCellTime::createVariables(Holon* holon) 
{
  Variable* variable = new Variable("Time", new Time());
  holon->addVariable(variable);
  
  variable = new Variable("Iteration", new Iteration());
  holon->addVariable(variable);
}
