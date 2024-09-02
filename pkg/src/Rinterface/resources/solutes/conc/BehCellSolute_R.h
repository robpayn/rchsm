/*
 * BehCellSolute_R.h
 */

#ifndef RINTERFACE_RESOURCES_SOLUTES_CONC_BEHCELLSOLUTE_R_H_
#define RINTERFACE_RESOURCES_SOLUTES_CONC_BEHCELLSOLUTE_R_H_

#include <R.h>
#include <Rinternals.h>

void BehCellSolute_finalizer(SEXP);

extern "C"
{
  SEXP BehCellSolute_constructor(SEXP, SEXP, SEXP);
  SEXP BehCellSolute_destructor(SEXP);
  SEXP BehCellSolute_createVariables(SEXP, SEXP, SEXP, SEXP);
}

#endif /* RINTERFACE_RESOURCES_SOLUTES_CONC_BEHCELLSOLUTE_R_H_ */
