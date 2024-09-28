/*
 * RateAdvection_R.cpp
 */

#include "RateAdvection_R.h"
#include "../../../../resources/solutes/conc/RateAdvection.h"

void RateAdvection_finalizer(SEXP externalPointer) 
{
  RateAdvection* pointer = 
    static_cast<RateAdvection*>(R_ExternalPtrAddr(externalPointer));
  R_ClearExternalPtr(externalPointer);
  delete pointer;
}

SEXP RateAdvection_destructor(SEXP externalPointer)
{
  RateAdvection_finalizer(externalPointer);
  
  return R_NilValue;
}

SEXP RateAdvection_constructor(
  SEXP initValue, 
  SEXP stateName, 
  SEXP velocityName, 
  SEXP phase, 
  SEXP regFinalizer
)
{
  RateAdvection* pointer = new RateAdvection(
    asReal(initValue),
    CHAR(asChar(stateName)),
    CHAR(asChar(velocityName)),
    asInteger(phase)
  );
  
  SEXP externalPointer = PROTECT(
    R_MakeExternalPtr(pointer, R_NilValue, R_NilValue)
  );
  
  if(asLogical(regFinalizer)) {
    R_RegisterCFinalizer(externalPointer, RateAdvection_finalizer);
  }
  
  UNPROTECT(1);
  
  return externalPointer;
}
