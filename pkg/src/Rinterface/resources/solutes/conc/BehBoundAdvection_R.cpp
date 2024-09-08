/*
 * BehBoundAdvection_R.cpp
 */

#include "BehBoundAdvection_R.h"
#include "../../../../resources/solutes/conc/BehBoundAdvection.h"
#include "../../../../CHSM/Bound.h"

void BehBoundAdvection_finalizer(SEXP externalPointer) 
{
  BehBoundAdvection* pointer = 
    static_cast<BehBoundAdvection*>(R_ExternalPtrAddr(externalPointer));
  R_ClearExternalPtr(externalPointer);
  delete pointer;
}

SEXP BehBoundAdvection_destructor(SEXP externalPointer)
{
  BehBoundAdvection_finalizer(externalPointer);
  
  return R_NilValue;
}

SEXP BehBoundAdvection_constructor(SEXP soluteName, SEXP regFinalizer)
{
  BehBoundAdvection* pointer = new BehBoundAdvection(CHAR(asChar(soluteName)));
  
  SEXP externalPointer = PROTECT(
    R_MakeExternalPtr(pointer, R_NilValue, R_NilValue)
  );
  
  if(asLogical(regFinalizer)) {
    R_RegisterCFinalizer(externalPointer, BehBoundAdvection_finalizer);
  }
  
  UNPROTECT(1);
  
  return externalPointer;
}

SEXP BehBoundAdvection_createVariables(
  SEXP rPointerBeh, 
  SEXP rPointerMatrix,
  SEXP rPointerBound,
  SEXP initRate
)
{
  BehBoundAdvection* pointerBeh = 
    static_cast <BehBoundAdvection*> (R_ExternalPtrAddr(rPointerBeh));
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
