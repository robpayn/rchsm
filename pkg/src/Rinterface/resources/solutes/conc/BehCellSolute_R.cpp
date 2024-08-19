/*
 * BehCellSolute_R.cpp
 */

#include "BehCellSolute_R.h"
#include "../../../../CHSM/Cell.h"

void BehCellSolute_finalizer(SEXP externalPointer) {
  
  BehCellSolute* pointer = (BehCellSolute*)R_ExternalPtrAddr(externalPointer);
  R_ClearExternalPtr(externalPointer);
  delete pointer;
  
}

SEXP BehCellSolute_destructor(SEXP externalPointer)
{
  BehCellSolute_finalizer(externalPointer);
  
  return R_NilValue;
}

SEXP BehCellSolute_constructor(SEXP soluteName, SEXP regFinalizer)
{
  BehCellSolute* pointer = new BehCellSolute(CHAR(asChar(soluteName)));
  
  SEXP externalPointer = PROTECT(
    R_MakeExternalPtr(pointer, R_NilValue, R_NilValue)
  );
  
  if(asLogical(regFinalizer)) {
    R_RegisterCFinalizer(externalPointer, BehCellSolute_finalizer);
  }
  
  UNPROTECT(1);
  
  return externalPointer;
}

SEXP BehCellSolute_createVariables(
  SEXP rPointerBeh, 
  SEXP rPointerMachine,
  SEXP rPointerCell,
  SEXP initValue
)
{
  BehCellSolute* pointerBeh = 
    static_cast <BehCellSolute*> (R_ExternalPtrAddr(rPointerBeh));
  Machine* pointerMachine =
    static_cast <Machine*> (R_ExternalPtrAddr(rPointerMachine));
  Cell* pointerCell =
    static_cast <Cell*> (R_ExternalPtrAddr(rPointerCell));
  
  pointerBeh->createVariables(
    pointerMachine, 
    pointerCell,
    asReal(initValue)
  );
  
  return R_NilValue;
}
