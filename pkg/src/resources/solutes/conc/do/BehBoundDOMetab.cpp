/*
 * BehBoundDOMetab.cpp
 */

#include "BehBoundDOMetab.h"
#include "../../../../Matrix.h"
#include "RateDOGPP.h"
#include "RateDOER.h"

void BehBoundDOMetab::createVariables(
    Matrix* matrix, 
    Holon& holon, 
    double initDOGPP,
    double initDOER
) 
{
  int phase = 1;
  matrix->createVariable(
      "DOGPP", 
      new RateDOGPP(phase, initDOGPP, "DOConc"), 
      holon
  );
  matrix->createVariable(
      "DOER", 
      new RateDOER(phase, initDOER, "DOConc"), 
      holon
  );
}
