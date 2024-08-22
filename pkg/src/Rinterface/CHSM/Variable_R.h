/**
 * Variable_R.h
 */

#ifndef RINTERFACE_CHSM_VARIABLE_R_H_
#define RINTERFACE_CHSM_VARIABLE_R_H_

#include <R.h>
#include <Rinternals.h>

extern "C"
{
  SEXP Variable_getValueString(SEXP);
}

#endif /* RINTERFACE_CHSM_VARIABLE_R_H_ */