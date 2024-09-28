/*
 * Iteration_R.h
 */

#ifndef RINTERFACE_RESOURCES_TIME_BASIC_ITERATION_R_H_
#define RINTERFACE_RESOURCES_TIME_BASIC_ITERATION_R_H_

#include <R.h>
#include <Rinternals.h>

void Iteration_finalizer(SEXP);

extern "C"
{
  SEXP Iteration_constructor(SEXP, SEXP, SEXP);
  SEXP Iteration_destructor(SEXP);
}

#endif /* RINTERFACE_RESOURCES_TIME_BASIC_ITERATION_R_H_ */
