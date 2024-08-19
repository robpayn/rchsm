/*
 * BehCellSolute_R.h
 */

#ifndef RINTERFACE_RESOURCES_SOLUTES_CONC_BEHCELLSOLUTE_R_H_
#define RINTERFACE_RESOURCES_SOLUTES_CONC_BEHCELLSOLUTE_R_H_

#include <R.h>
#include <Rinternals.h>
#include "../../../../resources/solutes/conc/BehCellSolute.h"

extern "C"
{
  SEXP BehCellSolute_constructor(SEXP, SEXP);
  SEXP BehCellSolute_destructor(SEXP);
  SEXP BehCellSolute_createVariables(SEXP, SEXP, SEXP, SEXP);
}

#endif /* RINTERFACE_RESOURCES_SOLUTES_CONC_BEHCELLSOLUTE_R_H_ */
