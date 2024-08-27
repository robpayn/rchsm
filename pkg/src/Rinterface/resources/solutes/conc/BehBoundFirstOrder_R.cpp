/*
 * BehBoundFirstOrder_R.cpp
 */

#include "BehBoundFirstOrder_R.h"
#include "../../../../resources/solutes/conc/BehBoundFirstOrder.h"
#include "../../../../CHSM/Bound.h"

void BehBoundFirstOrder_finalizer(SEXP externalPointer) {
  
  BehBoundFirstOrder* pointer = 
    static_cast<BehBoundFirstOrder*>(R_ExternalPtrAddr(externalPointer));
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
  SEXP rPointerMatrix,
  SEXP rPointerBound,
  SEXP initRate
)
{
  
  BehBoundFirstOrder* pointerBeh = 
    static_cast <BehBoundFirstOrder*> (R_ExternalPtrAddr(rPointerBeh));
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
