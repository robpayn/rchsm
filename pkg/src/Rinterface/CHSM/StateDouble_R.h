/*
 * StateDouble_R.h
 */

#ifndef RINTERFACE_CHSM_STATEDOUBLE_R_H_
#define RINTERFACE_CHSM_STATEDOUBLE_R_H_

#include <R.h>
#include <Rinternals.h>

void StateDouble_finalizer(SEXP);

extern "C"
{
  SEXP StateDouble_constructor(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
  SEXP StateDouble_destructor(SEXP);
}

#endif /* RINTERFACE_CHSM_STATEDOUBLE_R_H_ */
