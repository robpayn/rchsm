/*
 * Solver.h
 */

#ifndef RINTERFACE_CHSM_SOLVER_R_H_
#define RINTERFACE_CHSM_SOLVER_R_H_

#include <R.h>
#include <Rinternals.h>

void SolverForwardEuler_finalizer(SEXP);

extern "C"
{
  SEXP SolverForwardEuler_constructor(SEXP);
  SEXP SolverForwardEuler_destructor(SEXP);
}

#endif /* RINTERFACE_CHSM_SOLVER_R_H_ */