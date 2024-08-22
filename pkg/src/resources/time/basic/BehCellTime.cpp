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
  int phase = -1;
  machine->createVariable("Time", new Time(phase), holon);
  machine->createVariable("Iteration", new Iteration(phase), holon);
  machine->createVariable("TimeValid", new TimeValid(phase), holon);
}

void BehCellTime::createVariables(
  Machine* machine, 
  Holon* holon,
  double initTime,
  long initIteration,
  bool initTimeValid
) 
{
  int phase = 0;
  machine->createVariable("Time", new Time(phase, initTime), holon);
  machine->createVariable(
    "Iteration", 
    new Iteration(phase, initIteration), 
    holon
  );
  machine->createVariable(
    "TimeValid", 
    new TimeValid(phase, initTimeValid), 
    holon
  );
}
