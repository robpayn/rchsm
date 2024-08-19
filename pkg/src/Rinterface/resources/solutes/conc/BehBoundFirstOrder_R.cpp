/*
 * BehBoundFirstOrder_R.cpp
 */

#include "BehBoundFirstOrder_R.h"
#include "../../../../CHSM/Bound.h"

void BehBoundFirstOrder_finalizer(SEXP externalPointer) {
  
  BehBoundFirstOrder* pointer = (BehBoundFirstOrder*)R_ExternalPtrAddr(externalPointer);
  R_ClearExternalPtr(externalPointer);
  delete pointer;
  
}

SEXP BehBoundFirstOrder_destructor(SEXP externalPointer)
{
  BehBoundFirstOrder_finalizer(externalPointer);
  
  return R_NilValue;
}

SEXP BehBoundFirstOrder_constructor(SEXP soluteName, SEXP regFinalizer)
{
  BehBoundFirstOrder* pointer = new BehBoundFirstOrder(CHAR(asChar(soluteName)));
  
  SEXP externalPointer = PROTECT(
    R_MakeExternalPtr(pointer, R_NilValue, R_NilValue)
  );
  
  if(asLogical(regFinalizer)) {
    R_RegisterCFinalizer(externalPointer, BehBoundFirstOrder_finalizer);
  }
  
  UNPROTECT(1);
  
  return externalPointer;
}

SEXP BehBoundFirstOrder_createVariables(
  SEXP rPointerBeh, 
  SEXP rPointerMachine,
  SEXP rPointerBound,
  SEXP initRate,
  SEXP initRateCoeff
)
{
  
  BehBoundFirstOrder* pointerBeh = 
    static_cast <BehBoundFirstOrder*> (R_ExternalPtrAddr(rPointerBeh));
  Machine* pointerMachine =
    static_cast <Machine*> (R_ExternalPtrAddr(rPointerMachine));
  Bound* pointerBound =
    static_cast <Bound*> (R_ExternalPtrAddr(rPointerBound));
  
  pointerBeh->createVariables(
    pointerMachine, 
    pointerBound,
    asReal(initRate),
    asReal(initRateCoeff)
  );
  
  return R_NilValue;
  
}
