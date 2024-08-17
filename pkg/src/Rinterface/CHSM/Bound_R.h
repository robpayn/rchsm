/*
 * Bound_R.h
 */

#ifndef RCHSM_BOUND_R_H_
#define RCHSM_BOUND_R_H_

#include <R.h>
#include <Rinternals.h>
#include "../../CHSM/Bound.h"

void Bound_finalizer(SEXP);
  
extern "C"
{
  SEXP Bound_constructor(SEXP, SEXP);
  SEXP Bound_destructor(SEXP);
}

#endif /* RCHSM_BOUND_R_H_ */