/*
 * BehBoundDOMetab.cpp
 */

#include "BehBoundDOMetab.h"
#include "../../../../Machine.h"
#include "RateDOGPP.h"
#include "RateDOER.h"

void BehBoundDOMetab::createVariables(Machine* machine, Holon* holon) {
  int phase = 1;
  machine->createVariable("DOGPP", new RateDOGPP(phase, "DOConc"), holon);
  machine->createVariable("DOER", new RateDOER(phase, "DOConc"), holon);
}

void BehBoundDOMetab::createVariables(
    Machine* machine, 
    Holon* holon, 
    double initDOGPP,
    double initDOER
) 
{
  int phase = 2;
  machine->createVariable(
      "DOGPP", 
      new RateDOGPP(phase, initDOGPP, "DOConc"), 
      holon
  );
  machine->createVariable(
      "DOER", 
      new RateDOER(phase, initDOER, "DOConc"), 
      holon
  );
}
