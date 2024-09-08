/*
 * BehBoundDispersion_R.h
 */

#ifndef RINTERFACE_RESOURCES_SOLUTES_CONC_BEHBOUNDDISPERSION_R_H_
#define RINTERFACE_RESOURCES_SOLUTES_CONC_BEHBOUNDDISPERSION_R_H_

#include <R.h>
#include <Rinternals.h>

void BehBoundDispersion_finalizer(SEXP);
  
extern "C"
{
  SEXP BehBoundDispersion_constructor(SEXP, SEXP);
  SEXP BehBoundDispersion_destructor(SEXP);
  SEXP BehBoundDispersion_createVariables(SEXP, SEXP, SEXP, SEXP);
}

#endif /* RINTERFACE_RESOURCES_SOLUTES_CONC_BEHBOUNDDISPERSION_R_H_ */
