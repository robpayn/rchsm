/*
 * Cell_R.h
 */

#ifndef RCHSM_CELL_R_H_
#define RCHSM_CELL_R_H_

#include <R.h>
#include <Rinternals.h>
#include "../../CHSM/Cell.h"

void Cell_finalizer(SEXP externalPointer);

extern "C"
{
  SEXP Cell_constructor(SEXP name);
  SEXP Cell_destructor(SEXP externalPointer);
}

#endif /* RCHSM_CELL_R_H_ */
