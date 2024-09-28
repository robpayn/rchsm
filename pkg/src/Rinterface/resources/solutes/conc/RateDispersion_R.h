/*
 * RateDispersion_R.h
 */

#ifndef RINTERFACE_RESOURCES_SOLUTES_CONC_RATEDISPERSION_R_H_
#define RINTERFACE_RESOURCES_SOLUTES_CONC_RATEDISPERSION_R_H_

#include <R.h>
#include <Rinternals.h>

void RateDispersion_finalizer(SEXP);
  
extern "C"
{
  SEXP RateDispersion_constructor(SEXP, SEXP, SEXP, SEXP, SEXP);
  SEXP RateDispersion_destructor(SEXP);
}

#endif /* RINTERFACE_RESOURCES_SOLUTES_CONC_RATEDISPERSION_R_H_ */
