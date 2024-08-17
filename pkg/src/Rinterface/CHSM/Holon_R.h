/*
 * Holon_R.h
 */

#ifndef RINTERFACE_CHSM_HOLON_R_H_
#define RINTERFACE_CHSM_HOLON_R_H_

#include <R.h>
#include <Rinternals.h>
#include "../../CHSM/Holon.h"

extern "C"
{
  SEXP Holon_getValueString(SEXP);
}

#endif /* RINTERFACE_CHSM_HOLON_R_H_ */