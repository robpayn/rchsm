/*
 * RateDispersion_R.cpp
 */

#include "RateDispersion_R.h"
#include "../../../../resources/solutes/conc/RateDispersion.h"

void RateDispersion_finalizer(SEXP externalPointer) 
{
  RateDispersion* pointer = 
    static_cast<RateDispersion*>(R_ExternalPtrAddr(externalPointer));
  R_ClearExternalPtr(externalPointer);
  delete pointer;
}

SEXP RateDispersion_destructor(SEXP externalPointer)
{
  RateDispersion_finalizer(externalPointer);
  
  return R_NilValue;
}

SEXP RateDispersion_constructor(
  SEXP initValue,
  SEXP stateName,
  SEXP coeffName,
  SEXP phase,
  SEXP regFinalizer
)
{
  RateDispersion* pointer = new RateDispersion(
    asReal(initValue),
    CHAR(asChar(stateName)),
    CHAR(asChar(coeffName)),
    asInteger(phase)
  );
  
  SEXP externalPointer = PROTECT(
    R_MakeExternalPtr(pointer, R_NilValue, R_NilValue)
  );
  
  if(asLogical(regFinalizer)) {
    R_RegisterCFinalizer(externalPointer, RateDispersion_finalizer);
  }
  
  UNPROTECT(1);
  
  return externalPointer;
}
