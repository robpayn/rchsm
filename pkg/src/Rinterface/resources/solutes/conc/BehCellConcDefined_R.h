/*
 * BehCellConcDefined_R.h
 */

#ifndef RINTERFACE_RESOURCES_SOLUTES_CONC_BEHCELLCONCDEFINED_R_H_
#define RINTERFACE_RESOURCES_SOLUTES_CONC_BEHCELLCONCDEFINED_R_H_

#include <R.h>
#include <Rinternals.h>

void BehCellConcDefined_finalizer(SEXP);

extern "C"
{
  SEXP BehCellConcDefined_constructor(SEXP, SEXP);
  SEXP BehCellConcDefined_destructor(SEXP);
  SEXP BehCellConcDefined_createVariables(
    SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP
  );
}

#endif /* RINTERFACE_RESOURCES_SOLUTES_CONC_BEHCELLCONCDEFINED_R_H_ */
