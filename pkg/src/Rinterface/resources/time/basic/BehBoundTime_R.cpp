/*
 * BehBoundTime_R.cpp
 */

#include "BehBoundTime_R.h"
#include "../../../../CHSM/Bound.h"

void BehBoundTime_finalizer(SEXP externalPointer) 
{
  BehBoundTime* pointer = (BehBoundTime*)R_ExternalPtrAddr(externalPointer);
  R_ClearExternalPtr(externalPointer);
  delete pointer;
}

SEXP BehBoundTime_destructor(SEXP externalPointer)
{
  BehBoundTime_finalizer(externalPointer);
  
  return R_NilValue;
}

SEXP BehBoundTime_constructor()
{
  BehBoundTime* pointer = new BehBoundTime();
  
  SEXP externalPointer = PROTECT(
    R_MakeExternalPtr(pointer, R_NilValue, R_NilValue)
  );
  
  R_RegisterCFinalizer(
    externalPointer,
    BehBoundTime_finalizer
  );
  
  UNPROTECT(1);
  
  return externalPointer;
}

SEXP BehBoundTime_createVariables(
    SEXP rPointerBeh,
    SEXP rPointerMachine,
    SEXP rPointerBound,
    SEXP initTimeStep
)
{
  BehBoundTime* pointerBeh = 
    static_cast <BehBoundTime*> (R_ExternalPtrAddr(rPointerBeh));
  Machine* pointerMachine =
    static_cast <Machine*> (R_ExternalPtrAddr(rPointerMachine));
  Bound* pointerBound =
    static_cast <Bound*> (R_ExternalPtrAddr(rPointerBound));
  
  pointerBeh->createVariables(
    pointerMachine, 
    pointerBound, 
    asReal(initTimeStep)
  );
  
  return R_NilValue;
}
