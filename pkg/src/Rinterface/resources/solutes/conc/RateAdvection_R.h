/*
 * RateAdvection_R.h
 */

#ifndef RINTERFACE_RESOURCES_SOLUTES_CONC_RATEADVECTION_R_H_
#define RINTERFACE_RESOURCES_SOLUTES_CONC_RATEADVECTION_R_H_

#include <R.h>
#include <Rinternals.h>

void RateAdvection_finalizer(SEXP);
  
extern "C"
{
  SEXP RateAdvection_constructor(SEXP, SEXP, SEXP, SEXP, SEXP);
  SEXP RateAdvection_destructor(SEXP);
}


#endif /* RINTERFACE_RESOURCES_SOLUTES_CONC_RATEADVECTION_R_H_ */
