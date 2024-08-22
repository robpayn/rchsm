/*
 * BehBoundDOMetab_R.h
 */

#ifndef RESOURCES_SOLUTES_DO_CONC_BEHBOUNDDOMETAB_R_H_
#define RESOURCES_SOLUTES_DO_CONC_BEHBOUNDDOMETAB_R_H_

#include <R.h>
#include <Rinternals.h>

extern "C"
{
  SEXP BehBoundDOMetab_constructor(SEXP);
  SEXP BehBoundDOMetab_destructor(SEXP);
  SEXP BehBoundDOMetab_createVariables(SEXP, SEXP, SEXP, SEXP, SEXP);
}

#endif /* RESOURCES_SOLUTES_DO_CONC_BEHBOUNDDOMETAB_R_H_ */
