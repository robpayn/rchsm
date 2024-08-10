/*
 * BehCellTime.cpp
 */

#include "BehCellTime.h"
#include "Time.h"
#include "Iteration.h"
#include "TimeValid.h"
#include "../../../Machine.h"

BehCellTime::BehCellTime() {}

void BehCellTime::createVariables(Machine* machine, Holon* holon) 
{
  machine->createVariable("Time", new Time(), holon);
  machine->createVariable("Iteration", new Iteration(), holon);
  machine->createVariable("TimeValid", new TimeValid(), holon);
  machine->createVariable("TimeMax", new ValueDouble(), holon);
}

void BehCellTime::createVariables(
  Machine* machine, 
  Holon* holon,
  double initTime,
  long initIteration,
  bool initTimeValid,
  double initTimeMax
) 
{
  machine->createVariable("Time", new Time(initTime), holon);
  machine->createVariable("Iteration", new Iteration(initIteration), holon);
  machine->createVariable("TimeValid", new TimeValid(initTimeValid), holon);
  machine->createVariable("TimeMax", new ValueDouble(initTimeMax), holon);
}
