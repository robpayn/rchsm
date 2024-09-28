/*
 * TimeValid_R.cpp
 */

#include "TimeValid_R.h"
#include "../../../../resources/time/basic/TimeValid.h"

void TimeValid_finalizer(SEXP externalPointer) 
{
  TimeValid* pointer = (TimeValid*)R_ExternalPtrAddr(externalPointer);
  R_ClearExternalPtr(externalPointer);
  delete pointer;
}

SEXP TimeValid_destructor(SEXP externalPointer)
{
  TimeValid_finalizer(externalPointer);
  
  return R_NilValue;
}

SEXP TimeValid_constructor(SEXP initValue, SEXP phase, SEXP regFinalizer)
{
  TimeValid* pointer = new TimeValid(asLogical(initValue), asInteger(phase));
  
  SEXP externalPointer = PROTECT(
    R_MakeExternalPtr(pointer, R_NilValue, R_NilValue)
  );
  
  if(asLogical(regFinalizer)) {
    R_RegisterCFinalizer(externalPointer, TimeValid_finalizer);
  }
  
  UNPROTECT(1);
  
  return externalPointer;
}
