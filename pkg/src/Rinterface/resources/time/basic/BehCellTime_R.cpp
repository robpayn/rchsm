/*
 * BehCellTime_R.cpp
 */

#include "BehCellTime_R.h"
#include "../../../../resources/time/basic/BehCellTime.h"
#include "../../../../CHSM/Cell.h"

void BehCellTime_finalizer(SEXP externalPointer) 
{
  BehCellTime* pointer = (BehCellTime*)R_ExternalPtrAddr(externalPointer);
  R_ClearExternalPtr(externalPointer);
  delete pointer;
}

SEXP BehCellTime_destructor(SEXP externalPointer)
{
  BehCellTime_finalizer(externalPointer);
  
  return R_NilValue;
}

SEXP BehCellTime_constructor(SEXP regFinalizer)
{
  BehCellTime* pointer = new BehCellTime();
  
  SEXP externalPointer = PROTECT(
    R_MakeExternalPtr(pointer, R_NilValue, R_NilValue)
  );
  
  if(asLogical(regFinalizer)) {
    R_RegisterCFinalizer(externalPointer, BehCellTime_finalizer);
  }
  
  UNPROTECT(1);
  
  return externalPointer;
}

SEXP BehCellTime_createVariables(
  SEXP rPointerBeh,
  SEXP rPointerMatrix,
  SEXP rPointerCell,
  SEXP initTime,
  SEXP initIteration,
  SEXP initTimeValid
)
{
  BehCellTime* pointerBeh = 
    static_cast <BehCellTime*> (R_ExternalPtrAddr(rPointerBeh));
  Matrix* pointerMatrix =
    static_cast <Matrix*> (R_ExternalPtrAddr(rPointerMatrix));
  Cell* pointerCell =
    static_cast <Cell*> (R_ExternalPtrAddr(rPointerCell));
  
  pointerBeh->createVariables(
    pointerMatrix, 
    *pointerCell,
    asReal(initTime),
    asInteger(initIteration),
    asInteger(initTimeValid)
  );
  
  return R_NilValue;
}
