/*
 * Value_R.cpp
 */

#include "Value_R.h"
#include "../../CHSM/values/ValueDouble.h"

void ValueDouble_finalizer(SEXP externalPointer) 
{
  ValueDouble* pointer = 
    static_cast<ValueDouble*>(R_ExternalPtrAddr(externalPointer));
  R_ClearExternalPtr(externalPointer);
  delete pointer;
}

SEXP ValueDouble_destructor(SEXP externalPointer)
{
  ValueDouble_finalizer(externalPointer);
  
  return R_NilValue;
}

SEXP ValueDouble_constructor(SEXP initValue, SEXP regFinalizer)
{
  ValueDouble* pointer = new ValueDouble(asReal(initValue));
  
  SEXP externalPointer = PROTECT(
    R_MakeExternalPtr(pointer, R_NilValue, R_NilValue)
  );
  
  if(asLogical(regFinalizer)) {
    R_RegisterCFinalizer(externalPointer, ValueDouble_finalizer);
  }
  
  UNPROTECT(1);
  
  return externalPointer;
}
