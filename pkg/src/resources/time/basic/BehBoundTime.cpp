/*
 * BehBoundTime.cpp
 */

#include "BehBoundTime.h"
#include "TimeStep.h"
#include <string>
#include <iostream>

BehBoundTime::BehBoundTime() {}

void BehBoundTime::createVariables(Holon* holon) 
{
  Variable* variable = new Variable("TimeStep", new TimeStep());
  holon->addVariable(variable);
}
