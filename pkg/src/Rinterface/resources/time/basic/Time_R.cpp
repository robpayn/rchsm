/*
 * Time_R.cpp
 */

#include "Time_R.h"
#include "../../../../resources/time/basic/Time.h"

void Time_finalizer(SEXP externalPointer) 
{
  Time* pointer = (Time*)R_ExternalPtrAddr(externalPointer);
  R_ClearExternalPtr(externalPointer);
  delete pointer;
}

SEXP Time_destructor(SEXP externalPointer)
{
  Time_finalizer(externalPointer);
  
  return R_NilValue;
}

SEXP Time_constructor(SEXP initValue, SEXP phase, SEXP regFinalizer)
{
  Time* pointer = new Time(asReal(initValue), asInteger(phase));
  
  SEXP externalPointer = PROTECT(
    R_MakeExternalPtr(pointer, R_NilValue, R_NilValue)
  );
  
  if(asLogical(regFinalizer)) {
    R_RegisterCFinalizer(externalPointer, Time_finalizer);
  }
  
  UNPROTECT(1);
  
  return externalPointer;
}
