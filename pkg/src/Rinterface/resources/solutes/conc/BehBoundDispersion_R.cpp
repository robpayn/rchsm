/*
 * BehBoundDispersion_R.cpp
 */

#include "BehBoundDispersion_R.h"
#include "../../../../resources/solutes/conc/BehBoundDispersion.h"
#include "../../../../CHSM/Bound.h"

void BehBoundDispersion_finalizer(SEXP externalPointer) 
{
  BehBoundDispersion* pointer = 
    static_cast<BehBoundDispersion*>(R_ExternalPtrAddr(externalPointer));
  R_ClearExternalPtr(externalPointer);
  delete pointer;
}

SEXP BehBoundDispersion_destructor(SEXP externalPointer)
{
  BehBoundDispersion_finalizer(externalPointer);
  
  return R_NilValue;
}

SEXP BehBoundDispersion_constructor(SEXP soluteName, SEXP regFinalizer)
{
  BehBoundDispersion* pointer = new BehBoundDispersion(CHAR(asChar(soluteName)));
  
  SEXP externalPointer = PROTECT(
    R_MakeExternalPtr(pointer, R_NilValue, R_NilValue)
  );
  
  if(asLogical(regFinalizer)) {
    R_RegisterCFinalizer(externalPointer, BehBoundDispersion_finalizer);
  }
  
  UNPROTECT(1);
  
  return externalPointer;
}

SEXP BehBoundDispersion_createVariables(
  SEXP rPointerBeh, 
  SEXP rPointerMatrix,
  SEXP rPointerBound,
  SEXP initRate
)
{
  BehBoundDispersion* pointerBeh = 
    static_cast <BehBoundDispersion*> (R_ExternalPtrAddr(rPointerBeh));
  Matrix* pointerMatrix =
    static_cast <Matrix*> (R_ExternalPtrAddr(rPointerMatrix));
  Bound* pointerBound =
    static_cast <Bound*> (R_ExternalPtrAddr(rPointerBound));
  
  pointerBeh->createVariables(
    pointerMatrix, 
    *pointerBound,
    asReal(initRate)
  );
  
  return R_NilValue;
}
