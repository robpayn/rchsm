/*
 * BehBoundAdvection_R.h
 */

#ifndef RINTERFACE_RESOURCES_SOLUTES_CONC_BEHBOUNDADVECTION_R_H_
#define RINTERFACE_RESOURCES_SOLUTES_CONC_BEHBOUNDADVECTION_R_H_

#include <R.h>
#include <Rinternals.h>

void BehBoundAdvection_finalizer(SEXP);
  
extern "C"
{
  SEXP BehBoundAdvection_constructor(SEXP, SEXP);
  SEXP BehBoundAdvection_destructor(SEXP);
  SEXP BehBoundAdvection_createVariables(SEXP, SEXP, SEXP, SEXP);
}

#endif /* RINTERFACE_RESOURCES_SOLUTES_CONC_BEHBOUNDADVECTION_R_H_ */
