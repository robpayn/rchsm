/*
 * Holon_R.h
 */

#ifndef RINTERFACE_CHSM_HOLON_R_H_
#define RINTERFACE_CHSM_HOLON_R_H_

#include <R.h>
#include <Rinternals.h>

extern "C"
{
  SEXP Holon_getVariable(SEXP, SEXP);
}

#endif /* RINTERFACE_CHSM_HOLON_R_H_ */