/*
 * Bound_R.h
 */

#include <R.h>
#include <Rinternals.h>
#include "../CHSM/Bound.h"

void Bound_finalizer(SEXP externalPointer);
  
extern "C"
{
  SEXP Bound_constructor(SEXP name);
  SEXP Bound_destructor(SEXP externalPointer);
}