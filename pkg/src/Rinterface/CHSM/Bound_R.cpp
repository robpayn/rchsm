/*
 * Bound_R.cpp
 */

#include "Bound_R.h"

void Bound_finalizer(SEXP externalPointer) {
  
  Bound* pointer = static_cast <Bound*> (R_ExternalPtrAddr(externalPointer));
  R_ClearExternalPtr(externalPointer);
  delete pointer;
  
}

SEXP Bound_destructor(SEXP externalPointer)
{
  Bound_finalizer(externalPointer);
  
  return R_NilValue;
}

SEXP Bound_constructor(SEXP name, SEXP regFinalizer)
{
  Bound* pointer = new Bound(CHAR(asChar(name)));
  
  SEXP externalPointer = PROTECT(
    R_MakeExternalPtr(pointer, R_NilValue, R_NilValue)
  );
  
  if(asLogical(regFinalizer)) {
    R_RegisterCFinalizer(externalPointer, Bound_finalizer);
  }
  
  UNPROTECT(1);
  
  return externalPointer;
}
