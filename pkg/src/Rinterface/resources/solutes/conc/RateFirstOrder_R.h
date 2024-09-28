/*
 * RateFirstOrder_R.h
 */

#ifndef RINTERFACE_RESOURCES_SOLUTES_CONC_RATEFIRSTORDER_R_H_
#define RINTERFACE_RESOURCES_SOLUTES_CONC_RATEFIRSTORDER_R_H_

#include <R.h>
#include <Rinternals.h>

void RateFirstOrder_finalizer(SEXP);
  
extern "C"
{
  SEXP RateFirstOrder_constructor(SEXP, SEXP, SEXP, SEXP, SEXP);
  SEXP RateFirstOrder_destructor(SEXP);
}

#endif /* RINTERFACE_RESOURCES_SOLUTES_CONC_RATEFIRSTORDER_R_H_ */
