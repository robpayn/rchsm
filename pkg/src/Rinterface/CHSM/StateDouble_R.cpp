/*
 * StateDouble_R.cpp
 */

#include "StateDouble_R.h"
#include "../../CHSM/values/StateDouble.h"
#include "../../CHSM/values/MemoryDoubleFactory.h"

void StateDouble_finalizer(SEXP externalPointer) 
{
  StateDouble* pointer = 
    static_cast<StateDouble*>(R_ExternalPtrAddr(externalPointer));
  R_ClearExternalPtr(externalPointer);
  delete pointer;
}

SEXP StateDouble_destructor(SEXP externalPointer)
{
  StateDouble_finalizer(externalPointer);
  
  return R_NilValue;
}

SEXP StateDouble_constructor(
  SEXP extPointerTimeHolon,
  SEXP timeStepName,
  SEXP initValue,
  SEXP phase,
  SEXP rPointerMFDouble,
  SEXP regFinalizer
)
{
  Holon* pointerTimeHolon = static_cast<Holon*>(
    R_ExternalPtrAddr(extPointerTimeHolon)
  );

  MemoryDoubleFactory* pointerMFDouble;
  if (rPointerMFDouble == R_NilValue) {
    pointerMFDouble = nullptr;
  } else {
    pointerMFDouble = 
      static_cast<MemoryDoubleFactory*>(R_ExternalPtrAddr(rPointerMFDouble));
  }
  
  StateDouble* pointer = new StateDouble(
    *pointerTimeHolon,
    CHAR(asChar(timeStepName)),
    asReal(initValue),
    asInteger(phase)
  );
  if (pointerMFDouble) {
    pointerMFDouble->createMemory(pointer);
  }
  
  SEXP externalPointer = PROTECT(
    R_MakeExternalPtr(pointer, R_NilValue, R_NilValue)
  );
  
  if(asLogical(regFinalizer)) {
    R_RegisterCFinalizer(externalPointer, StateDouble_finalizer);
  }
  
  UNPROTECT(1);
  
  return externalPointer;
}
