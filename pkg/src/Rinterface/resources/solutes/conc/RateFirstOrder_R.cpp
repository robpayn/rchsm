/*
 * RateFirstOrder_R.cpp
 */

#include "RateFirstOrder_R.h"
#include "../../../../resources/solutes/conc/RateFirstOrder.h"

void RateFirstOrder_finalizer(SEXP externalPointer) {
  
  RateFirstOrder* pointer = 
    static_cast<RateFirstOrder*>(R_ExternalPtrAddr(externalPointer));
  R_ClearExternalPtr(externalPointer);
  delete pointer;
  
}

SEXP RateFirstOrder_destructor(SEXP externalPointer)
{
  RateFirstOrder_finalizer(externalPointer);
  
  return R_NilValue;
}

SEXP RateFirstOrder_constructor(
  SEXP initValue,
  SEXP stateName, 
  SEXP coeffName,
  SEXP phase,
  SEXP regFinalizer
)
{
  RateFirstOrder* pointer = new RateFirstOrder(
    asReal(initValue),
    CHAR(asChar(stateName)),
    CHAR(asChar(coeffName)),
    asInteger(phase)
  );
  
  SEXP externalPointer = PROTECT(
    R_MakeExternalPtr(pointer, R_NilValue, R_NilValue)
  );
  
  if(asLogical(regFinalizer)) {
    R_RegisterCFinalizer(externalPointer, RateFirstOrder_finalizer);
  }
  
  UNPROTECT(1);
  
  return externalPointer;
}
