/*
 * Bound_R.h
 */

#ifndef RCHSM_BOUND_R_H_
#define RCHSM_BOUND_R_H_

#include <R.h>
#include <Rinternals.h>
#include "../../CHSM/Bound.h"

void Bound_finalizer(SEXP externalPointer);
  
extern "C"
{
  SEXP Bound_constructor(SEXP name);
  SEXP Bound_destructor(SEXP externalPointer);
}

#endif /* RCHSM_BOUND_R_H_ */