/*
 * Iteration_R.cpp
 */

#include "Iteration_R.h"
#include "../../../../resources/time/basic/Iteration.h"

void Iteration_finalizer(SEXP externalPointer) 
{
  Iteration* pointer = (Iteration*)R_ExternalPtrAddr(externalPointer);
  R_ClearExternalPtr(externalPointer);
  delete pointer;
}

SEXP Iteration_destructor(SEXP externalPointer)
{
  Iteration_finalizer(externalPointer);
  
  return R_NilValue;
}

SEXP Iteration_constructor(SEXP initValue, SEXP phase, SEXP regFinalizer)
{
  Iteration* pointer = new Iteration(asInteger(initValue), asInteger(phase));
  
  SEXP externalPointer = PROTECT(
    R_MakeExternalPtr(pointer, R_NilValue, R_NilValue)
  );
  
  if(asLogical(regFinalizer)) {
    R_RegisterCFinalizer(externalPointer, Iteration_finalizer);
  }
  
  UNPROTECT(1);
  
  return externalPointer;
}
