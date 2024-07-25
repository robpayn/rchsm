/*
 * Cell_R.h
 */

#include <R.h>
#include <Rinternals.h>
#include "../CHSM/Cell.h"

void Cell_finalizer(SEXP externalPointer);

extern "C"
{
  SEXP Cell_constructor(SEXP name);
  SEXP Cell_destructor(SEXP externalPointer);
}