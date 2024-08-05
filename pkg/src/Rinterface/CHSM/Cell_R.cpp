/*
 * Cell_R.cpp
 */

#include "Cell_R.h"

void Cell_finalizer(SEXP externalPointer) {
  
  Cell* pointer = static_cast <Cell*> (R_ExternalPtrAddr(externalPointer));
  R_ClearExternalPtr(externalPointer);
  delete pointer;
  
}

SEXP Cell_destructor(SEXP externalPointer)
{
  Cell_finalizer(externalPointer);
  
  return R_NilValue;
}

SEXP Cell_constructor(SEXP name)
{
  Cell* pointer = new Cell(CHAR(asChar(name)));
  
  SEXP externalPointer = PROTECT(
    R_MakeExternalPtr(pointer, R_NilValue, R_NilValue)
  );
  
  R_RegisterCFinalizer(externalPointer, Cell_finalizer);
  
  UNPROTECT(1);
  
  return externalPointer;
}