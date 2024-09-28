/*
 * Solver.cpp
 */

#include "Solver_R.h"
#include "../../CHSM/SolverForwardEuler.h"
#include "../../CHSM/SolverRKTwo.h"
#include "../../CHSM/values/ValueDouble.h"

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

SEXP SolverForwardEuler_constructor(SEXP extTimeStepPtr, SEXP regFinalizer)
{
  
  Variable* timeStepPtr = 
    static_cast <Variable*> (R_ExternalPtrAddr(extTimeStepPtr));
  
  SolverForwardEuler* pointer = new SolverForwardEuler(
    timeStepPtr->getValue<ValueDouble>()->v_
  );
  
  SEXP externalPointer = PROTECT(
    R_MakeExternalPtr(pointer, R_NilValue, R_NilValue)
  );
  
  if(asLogical(regFinalizer)) {
    R_RegisterCFinalizer(externalPointer, SolverForwardEuler_finalizer);
  }
  
  UNPROTECT(1);
  
  return externalPointer;

}

void SolverRKTwo_finalizer(SEXP externalPointer) {
  
  SolverRKTwo* pointer = 
    static_cast <SolverRKTwo*> (R_ExternalPtrAddr(externalPointer));
  R_ClearExternalPtr(externalPointer);
  delete pointer;
  
}

SEXP SolverRKTwo_destructor(SEXP externalPointer)
{
  SolverRKTwo_finalizer(externalPointer);
  
  return R_NilValue;
}

SEXP SolverRKTwo_constructor(SEXP extTimeStepPtr, SEXP regFinalizer)
{
  
  Variable* timeStepPtr = 
    static_cast <Variable*> (R_ExternalPtrAddr(extTimeStepPtr));
  
  SolverRKTwo* pointer = new SolverRKTwo(
    timeStepPtr->getValue<ValueDouble>()->v_
  );
  
  SEXP externalPointer = PROTECT(
    R_MakeExternalPtr(pointer, R_NilValue, R_NilValue)
  );
  
  if(asLogical(regFinalizer)) {
    R_RegisterCFinalizer(externalPointer, SolverRKTwo_finalizer);
  }
  
  UNPROTECT(1);
  
  return externalPointer;
  
}