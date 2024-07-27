/*
 * Holon_R.h
 */

#ifndef RCHSM_HOLON_R_H_
#define RCHSM_HOLON_R_H_

#include <R.h>
#include <Rinternals.h>
#include "../CHSM/Holon.h"

extern "C"
{
  SEXP Holon_getValueString(SEXP);
}

#endif /* RCHSM_HOLON_R_H_ */