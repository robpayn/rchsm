/*
 * DepManager_R.cpp
 */

#include "DepManager_R.h"
#include "../../CHSM/DepManInstallOrder.h"

void DepManInstallOrder_finalizer(SEXP externalPointer) {
  
  DepManInstallOrder* pointer = 
    static_cast <DepManInstallOrder*> (R_ExternalPtrAddr(externalPointer));
  R_ClearExternalPtr(externalPointer);
  delete pointer;
  
}

SEXP DepManInstallOrder_destructor(SEXP externalPointer)
{
  DepManInstallOrder_finalizer(externalPointer);
  
  return R_NilValue;
}

SEXP DepManInstallOrder_constructor(SEXP numPhases, SEXP regFinalizer)
{
  
  DepManInstallOrder* pointer = new DepManInstallOrder(asInteger(numPhases));
  
  SEXP externalPointer = PROTECT(
    R_MakeExternalPtr(pointer, R_NilValue, R_NilValue)
  );
  
  if(asLogical(regFinalizer)) {
    R_RegisterCFinalizer(externalPointer, DepManInstallOrder_finalizer);
  }
  
  UNPROTECT(1);
  
  return externalPointer;
  
}