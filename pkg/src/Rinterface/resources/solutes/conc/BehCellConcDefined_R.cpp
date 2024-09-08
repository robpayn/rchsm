/*
 * BehCellConcDefined_R.cpp
 */

#include "BehCellConcDefined_R.h"
#include "../../../../resources/solutes/conc/BehCellConcDefined.h"
#include "../../../../CHSM/Cell.h"
#include "../../../../CHSM/values/MemoryDoubleFactory.h"
#include <iterator>

void BehCellConcDefined_finalizer(SEXP externalPointer) 
{
  BehCellConcDefined* pointer = 
    (BehCellConcDefined*)R_ExternalPtrAddr(externalPointer);
  R_ClearExternalPtr(externalPointer);
  delete pointer;
}

SEXP BehCellConcDefined_destructor(SEXP externalPointer)
{
  BehCellConcDefined_finalizer(externalPointer);
  
  return R_NilValue;
}

SEXP BehCellConcDefined_constructor(
  SEXP soluteName,
  SEXP regFinalizer
)
{
  BehCellConcDefined* pointer = new BehCellConcDefined(
    CHAR(asChar(soluteName))
  );
  
  SEXP externalPointer = PROTECT(
    R_MakeExternalPtr(pointer, R_NilValue, R_NilValue)
  );
  
  if(asLogical(regFinalizer)) {
    R_RegisterCFinalizer(externalPointer, BehCellConcDefined_finalizer);
  }
  
  UNPROTECT(1);
  
  return externalPointer;
}

SEXP BehCellConcDefined_createVariables(
  SEXP rPointerBeh, 
  SEXP rPointerMatrix,
  SEXP rPointerCell,
  SEXP rPointerTimeHolon,
  SEXP timeStepName,
  SEXP iterationName,
  SEXP rvalues,
  SEXP rPointerMFDouble
)
{
  BehCellConcDefined* pointerBeh = 
    static_cast <BehCellConcDefined*> (R_ExternalPtrAddr(rPointerBeh));
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
  
  std::vector<double> values(
    REAL(rvalues), 
    REAL(rvalues) + length(rvalues)
  );
  
  pointerBeh->createVariables(
    pointerMatrix, 
    *pointerCell,
    *pointerTimeHolon,
    CHAR(asChar(timeStepName)),
    CHAR(asChar(iterationName)),
    values,
    pointerMFDouble
  );
  
  return R_NilValue;
}
