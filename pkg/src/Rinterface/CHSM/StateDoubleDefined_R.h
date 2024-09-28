/*
 * StateDoubleDefined_R.h
 */

#ifndef RINTERFACE_CHSM_STATEDOUBLEDEFINED_R_H_
#define RINTERFACE_CHSM_STATEDOUBLEDEFINED_R_H_

#include <R.h>
#include <Rinternals.h>

void StateDoubleDefined_finalizer(SEXP);

extern "C"
{
  SEXP StateDoubleDefined_constructor(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
  SEXP StateDoubleDefined_destructor(SEXP);
}

#endif /* RINTERFACE_CHSM_STATEDOUBLEDEFINED_R_H_ */
