/*
 * Cell_R.h
 */

#ifndef RCHSM_CELL_R_H_
#define RCHSM_CELL_R_H_

#include <R.h>
#include <Rinternals.h>
#include "../../CHSM/Cell.h"

void Cell_finalizer(SEXP);

extern "C"
{
  SEXP Cell_constructor(SEXP, SEXP);
  SEXP Cell_destructor(SEXP);
}

#endif /* RCHSM_CELL_R_H_ */
