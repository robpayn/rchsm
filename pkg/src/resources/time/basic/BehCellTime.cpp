/*
 * BehCellTime.cpp
 */

#include "BehCellTime.h"
#include "../../../Matrix.h"
#include "Time.h"
#include "Iteration.h"
#include "TimeValid.h"

BehCellTime::BehCellTime() {}

void BehCellTime::createVariables(
  Matrix* matrix, 
  Holon& holon,
  double initTime,
  long initIteration,
  bool initTimeValid
) 
{
  int phase = 0;
  matrix->createVariable("Time", new Time(initTime, phase), holon);
  matrix->createVariable(
    "Iteration", 
    new Iteration(initIteration, phase), 
    holon
  );
  matrix->createVariable(
    "TimeValid", 
    new TimeValid(initTimeValid, phase), 
    holon
  );
}
