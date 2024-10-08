/*
 * BehCellSolute_R.cpp
 */

#include "BehCellSolute_R.h"
#include "../../../../resources/solutes/conc/BehCellSolute.h"
#include "../../../../CHSM/Cell.h"
#include "../../../../CHSM/values/MemoryDoubleFactory.h"

void BehCellSolute_finalizer(SEXP externalPointer) 
{
  BehCellSolute* pointer = (BehCellSolute*)R_ExternalPtrAddr(externalPointer);
  R_ClearExternalPtr(externalPointer);
  delete pointer;
}

SEXP BehCellSolute_destructor(SEXP externalPointer)
{
  BehCellSolute_finalizer(externalPointer);
  
  return R_NilValue;
}

SEXP BehCellSolute_constructor(
  SEXP soluteName,
  SEXP regFinalizer
)
{
  BehCellSolute* pointer = new BehCellSolute(
    CHAR(asChar(soluteName))
  );

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
  SEXP rPointerMatrix,
  SEXP rPointerCell,
  SEXP rPointerTimeHolon,
  SEXP timeStepName,
  SEXP initValue,
  SEXP rPointerMFDouble
)
{
  BehCellSolute* pointerBeh = 
    static_cast <BehCellSolute*> (R_ExternalPtrAddr(rPointerBeh));
  Matrix* pointerMatrix =
    static_cast <Matrix*> (R_ExternalPtrAddr(rPointerMatrix));
  Cell* pointerCell =
    static_cast <Cell*> (R_ExternalPtrAddr(rPointerCell));
  Holon* pointerTimeHolon =
    static_cast <Holon*> (R_ExternalPtrAddr(rPointerTimeHolon));
  MemoryDoubleFactory* pointerMFDouble;
  if (rPointerMFDouble == R_NilValue) {
    pointerMFDouble = nullptr;
  } else {
    pointerMFDouble =
      static_cast<MemoryDoubleFactory*>(R_ExternalPtrAddr(rPointerMFDouble));
  }
  
  pointerBeh->createVariables(
    pointerMatrix, 
    *pointerCell,
    *pointerTimeHolon,
    CHAR(asChar(timeStepName)),
    asReal(initValue),
    pointerMFDouble
  );
  
  return R_NilValue;
}
