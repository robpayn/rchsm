/*
 * BehDOConcCell_R.cpp
 */

#include "BehDOConcCell_R.h"
#include "../../../CHSM/Cell.h"

void BehDOConcCell_finalizer(SEXP externalPointer) {
  
  BehDOConcCell* pointer = (BehDOConcCell*)R_ExternalPtrAddr(externalPointer);
  R_ClearExternalPtr(externalPointer);
  delete pointer;
  
}

SEXP BehDOConcCell_destructor(SEXP externalPointer)
{
  BehDOConcCell_finalizer(externalPointer);
  
  return R_NilValue;
}

SEXP BehDOConcCell_constructor()
{
  BehDOConcCell* pointer = new BehDOConcCell();
  
  SEXP externalPointer = PROTECT(
    R_MakeExternalPtr(pointer, R_NilValue, R_NilValue)
  );
  
  R_RegisterCFinalizer(
    externalPointer,
    BehDOConcCell_finalizer
  );
  
  UNPROTECT(1);
  
  return externalPointer;
}

SEXP BehDOConcCell_createVariables(SEXP rPointerBeh, SEXP rPointerCell)
{
  BehDOConcCell* pointerBeh = 
    static_cast <BehDOConcCell*> (R_ExternalPtrAddr(rPointerBeh));
  Cell* pointerCell =
    static_cast <Cell*> (R_ExternalPtrAddr(rPointerCell));
  
  pointerBeh->createVariables(pointerCell);
  
  return R_NilValue;
}
