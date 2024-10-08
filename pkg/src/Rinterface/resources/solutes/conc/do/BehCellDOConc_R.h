/*
 * BehCellDOConc_R.h
 */

#ifndef RESOURCES_SOLUTES_DO_CONC_BEHCELLDOCONC_R_H_
#define RESOURCES_SOLUTES_DO_CONC_BEHCELLDOCONC_R_H_

#include <R.h>
#include <Rinternals.h>

extern "C"
{
  SEXP BehCellDOConc_constructor(SEXP);
  SEXP BehCellDOConc_destructor(SEXP);
  SEXP BehCellDOConc_createVariables(SEXP, SEXP, SEXP, SEXP);
}

#endif /* RESOURCES_SOLUTES_DO_CONC_BEHCELLDOCONC_R_H_ */
