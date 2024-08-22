/*
 * BehBoundFirstOrder_R.h
 */

#ifndef RINTERFACE_RESOURCES_SOLUTES_CONC_BEHBOUNDFIRSTORDER_R_H_
#define RINTERFACE_RESOURCES_SOLUTES_CONC_BEHBOUNDFIRSTORDER_R_H_

#include <R.h>
#include <Rinternals.h>

extern "C"
{
  SEXP BehBoundFirstOrder_constructor(SEXP, SEXP);
  SEXP BehBoundFirstOrder_destructor(SEXP);
  SEXP BehBoundFirstOrder_createVariables(SEXP, SEXP, SEXP, SEXP);
}

#endif /* RINTERFACE_RESOURCES_SOLUTES_CONC_BEHBOUNDFIRSTORDER_R_H_ */
