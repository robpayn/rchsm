/*
 * MemoryDoubleFactory_R.cpp
 */

#include "MemoryDoubleFactory_R.h"
#include "../../CHSM/values/MemoryDoubleFactory.h"

void MemoryDoubleFactory_finalizer(SEXP externalPointer) 
{
  MemoryDoubleFactory* pointer = 
    static_cast<MemoryDoubleFactory*>(R_ExternalPtrAddr(externalPointer));
  R_ClearExternalPtr(externalPointer);
  delete pointer;
}

SEXP MemoryDoubleFactory_destructor(SEXP externalPointer)
{
  MemoryDoubleFactory_finalizer(externalPointer);
  
  return R_NilValue;
}

SEXP MemoryDoubleFactory_constructor(
  SEXP size, 
  SEXP regFinalizer
)
{
  MemoryDoubleFactory* pointer = new MemoryDoubleFactory(asInteger(size));
  
  SEXP externalPointer = PROTECT(
    R_MakeExternalPtr(pointer, R_NilValue, R_NilValue)
  );
  
  if(asLogical(regFinalizer)) {
    R_RegisterCFinalizer(externalPointer, MemoryDoubleFactory_finalizer);
  }
  
  UNPROTECT(1);
  
  return externalPointer;
}
