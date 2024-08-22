/*
 * Value_R.h
 */

#ifndef RINTERFACE_CHSM_VALUE_R_H_
#define RINTERFACE_CHSM_VALUE_R_H_

#include <R.h>
#include <Rinternals.h>

void ValueDouble_finalizer(SEXP);

extern "C"
{
  SEXP ValueDouble_constructor(SEXP, SEXP);
  SEXP ValueDouble_destructor(SEXP);
}


#endif /* RINTERFACE_CHSM_VALUE_R_H_ */
