/*
 * BehCellDOConc_R.cpp
 */

#include "BehCellDOConc_R.h"
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

SEXP BehCellDOConc_constructor()
{
  BehCellDOConc* pointer = new BehCellDOConc();
  
  SEXP externalPointer = PROTECT(
    R_MakeExternalPtr(pointer, R_NilValue, R_NilValue)
  );
  
  R_RegisterCFinalizer(
    externalPointer,
    BehCellDOConc_finalizer
  );
  
  UNPROTECT(1);
  
  return externalPointer;
}

SEXP BehCellDOConc_createVariables(SEXP rPointerBeh, SEXP rPointerCell)
{
  BehCellDOConc* pointerBeh = 
    static_cast <BehCellDOConc*> (R_ExternalPtrAddr(rPointerBeh));
  Cell* pointerCell =
    static_cast <Cell*> (R_ExternalPtrAddr(rPointerCell));
  
  pointerBeh->createVariables(pointerCell);
  
  return R_NilValue;
}
