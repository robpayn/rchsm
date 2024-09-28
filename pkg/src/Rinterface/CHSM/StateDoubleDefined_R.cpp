/*
 * StateDoubleDefined_R.cpp
 */

#include "StateDoubleDefined_R.h"
#include "../../CHSM/values/StateDoubleDefined.h"
#include "../../CHSM/values/MemoryDoubleFactory.h"
#include <vector>

void StateDoubleDefined_finalizer(SEXP externalPointer) 
{
  StateDoubleDefined* pointer = 
    static_cast<StateDoubleDefined*>(R_ExternalPtrAddr(externalPointer));
  R_ClearExternalPtr(externalPointer);
  delete pointer;
}

SEXP StateDoubleDefined_destructor(SEXP externalPointer)
{
  StateDoubleDefined_finalizer(externalPointer);
  
  return R_NilValue;
}

SEXP StateDoubleDefined_constructor(
  SEXP extPointerTimeHolon,
  SEXP timeStepName,
  SEXP iterationName,
  SEXP rvalues,
  SEXP phase,
  SEXP rPointerMFDouble,
  SEXP regFinalizer
)
{
  Holon* pointerTimeHolon = static_cast<Holon*>(
    R_ExternalPtrAddr(extPointerTimeHolon)
  );
  std::vector<double> values(REAL(rvalues), REAL(rvalues) + length(rvalues));
  
  MemoryDoubleFactory* pointerMFDouble;
  if (rPointerMFDouble == R_NilValue) {
    pointerMFDouble = nullptr;
  } else {
    pointerMFDouble = 
      static_cast<MemoryDoubleFactory*>(R_ExternalPtrAddr(rPointerMFDouble));
  }
  
  StateDoubleDefined* pointer = new StateDoubleDefined(
    *pointerTimeHolon,
    CHAR(asChar(timeStepName)),
    CHAR(asChar(iterationName)),
    values,
    asInteger(phase)
  );
  if (pointerMFDouble) {
    pointerMFDouble->createMemory(pointer);
  }
  
  SEXP externalPointer = PROTECT(
    R_MakeExternalPtr(pointer, R_NilValue, R_NilValue)
  );
  
  if(asLogical(regFinalizer)) {
    R_RegisterCFinalizer(externalPointer, StateDoubleDefined_finalizer);
  }
  
  UNPROTECT(1);
  
  return externalPointer;
}
