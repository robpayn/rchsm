/*
 * BehBoundDOMetab_R.cpp
 */

#include "BehBoundDOMetab_R.h"
#include "../../../../../CHSM/Bound.h"

void BehBoundDOMetab_finalizer(SEXP externalPointer) {
  
  BehBoundDOMetab* pointer = (BehBoundDOMetab*)R_ExternalPtrAddr(externalPointer);
  R_ClearExternalPtr(externalPointer);
  delete pointer;
  
}

SEXP BehBoundDOMetab_destructor(SEXP externalPointer)
{
  BehBoundDOMetab_finalizer(externalPointer);
  
  return R_NilValue;
}

SEXP BehBoundDOMetab_constructor(SEXP regFinalizer)
{
  BehBoundDOMetab* pointer = new BehBoundDOMetab();
  
  SEXP externalPointer = PROTECT(
    R_MakeExternalPtr(pointer, R_NilValue, R_NilValue)
  );
  
  if(asLogical(regFinalizer)) {
    R_RegisterCFinalizer(externalPointer, BehBoundDOMetab_finalizer);
  }
  
  UNPROTECT(1);
  
  return externalPointer;
}

SEXP BehBoundDOMetab_createVariables(
  SEXP rPointerBeh, 
  SEXP rPointerMachine,
  SEXP rPointerBound,
  SEXP initDOGPP,
  SEXP initDOER
)
{
  
  BehBoundDOMetab* pointerBeh = 
    static_cast <BehBoundDOMetab*> (R_ExternalPtrAddr(rPointerBeh));
  Machine* pointerMachine =
    static_cast <Machine*> (R_ExternalPtrAddr(rPointerMachine));
  Bound* pointerBound =
    static_cast <Bound*> (R_ExternalPtrAddr(rPointerBound));
  
  pointerBeh->createVariables(
    pointerMachine, 
    pointerBound,
    asReal(initDOGPP),
    asReal(initDOER)
  );
  
  return R_NilValue;
  
}
