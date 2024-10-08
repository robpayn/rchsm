/*
 * BehCellDOConc_R.cpp
 */

#include "BehCellDOConc_R.h"
#include "../../../../../resources/solutes/conc/do/BehCellDOConc.h"
#include "../../../../../CHSM/Cell.h"

void BehCellDOConc_finalizer(SEXP externalPointer) {
  
  BehCellDOConc* pointer = (BehCellDOConc*)R_ExternalPtrAddr(externalPointer);
  R_ClearExternalPtr(externalPointer);
  delete pointer;
  
}

SEXP BehCellDOConc_destructor(SEXP externalPointer)
{
  BehCellDOConc_finalizer(externalPointer);
  
  return R_NilValue;
}

SEXP BehCellDOConc_constructor(SEXP regFinalizer)
{
  BehCellDOConc* pointer = new BehCellDOConc();
  
  SEXP externalPointer = PROTECT(
    R_MakeExternalPtr(pointer, R_NilValue, R_NilValue)
  );
  
  if(asLogical(regFinalizer)) {
    R_RegisterCFinalizer(externalPointer, BehCellDOConc_finalizer);
  }
  
  UNPROTECT(1);
  
  return externalPointer;
}

SEXP BehCellDOConc_createVariables(
  SEXP rPointerBeh, 
  SEXP rPointerMatrix,
  SEXP rPointerCell,
  SEXP initDOConc
)
{
  BehCellDOConc* pointerBeh = 
    static_cast <BehCellDOConc*> (R_ExternalPtrAddr(rPointerBeh));
  Matrix* pointerMatrix =
    static_cast <Matrix*> (R_ExternalPtrAddr(rPointerMatrix));
  Cell* pointerCell =
    static_cast <Cell*> (R_ExternalPtrAddr(rPointerCell));
  
  pointerBeh->createVariables(
    pointerMatrix, 
    *pointerCell,
    asReal(initDOConc)
  );
  
  return R_NilValue;
}
