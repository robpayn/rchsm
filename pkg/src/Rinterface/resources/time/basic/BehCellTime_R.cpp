/*
 * BehCellTime_R.cpp
 */

#include "BehCellTime_R.h"
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

SEXP BehCellTime_constructor()
{
  BehCellTime* pointer = new BehCellTime();
  
  SEXP externalPointer = PROTECT(
    R_MakeExternalPtr(pointer, R_NilValue, R_NilValue)
  );
  
  R_RegisterCFinalizer(
    externalPointer,
    BehCellTime_finalizer
  );
  
  UNPROTECT(1);
  
  return externalPointer;
}

SEXP BehCellTime_createVariables(
  SEXP rPointerBeh,
  SEXP rPointerMachine,
  SEXP rPointerCell,
  SEXP initTime,
  SEXP initIteration,
  SEXP initTimeValid,
  SEXP initTimeMax
)
{
  BehCellTime* pointerBeh = 
    static_cast <BehCellTime*> (R_ExternalPtrAddr(rPointerBeh));
  Machine* pointerMachine =
    static_cast <Machine*> (R_ExternalPtrAddr(rPointerMachine));
  Cell* pointerCell =
    static_cast <Cell*> (R_ExternalPtrAddr(rPointerCell));
  
  pointerBeh->createVariables(
    pointerMachine, 
    pointerCell,
    asReal(initTime),
    asInteger(initIteration),
    asInteger(initTimeValid),
    asReal(initTimeMax)
  );
  
  return R_NilValue;
}
