/*
 * Bound_R.h
 */

#ifndef RINTERFACE_CHSM_BOUND_R_H_
#define RINTERFACE_CHSM_BOUND_R_H_

#include <R.h>
#include <Rinternals.h>
#include "../../CHSM/Bound.h"

void Bound_finalizer(SEXP);
  
extern "C"
{
  SEXP Bound_constructor(SEXP, SEXP);
  SEXP Bound_destructor(SEXP);
}

#endif /* RINTERFACE_CHSM_BOUND_R_H_ */
