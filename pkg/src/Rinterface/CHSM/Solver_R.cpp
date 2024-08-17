/*
 * Solver.cpp
 */

#include "Solver_R.h"
#include "../../CHSM/SolverForwardEuler.h"

void SolverForwardEuler_finalizer(SEXP externalPointer) {
  
  SolverForwardEuler* pointer = 
    static_cast <SolverForwardEuler*> (R_ExternalPtrAddr(externalPointer));
  R_ClearExternalPtr(externalPointer);
  delete pointer;
  
}

SEXP SolverForwardEuler_destructor(SEXP externalPointer)
{
  SolverForwardEuler_finalizer(externalPointer);
  
  return R_NilValue;
}

SEXP SolverForwardEuler_constructor(SEXP regFinalizer)
{
  
  SolverForwardEuler* pointer = new SolverForwardEuler();
  
  SEXP externalPointer = PROTECT(
    R_MakeExternalPtr(pointer, R_NilValue, R_NilValue)
  );
  
  if(asLogical(regFinalizer)) {
    R_RegisterCFinalizer(externalPointer, SolverForwardEuler_finalizer);
  }
  
  UNPROTECT(1);
  
  return externalPointer;

}