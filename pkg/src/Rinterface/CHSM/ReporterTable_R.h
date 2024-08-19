/*
 * ReporterTable_R.h
 */

#ifndef RINTERFACE_CHSM_REPORTERTABLE_R_H_
#define RINTERFACE_CHSM_REPORTERTABLE_R_H_

#include <R.h>
#include <Rinternals.h>

void ReporterTable_finalizer(SEXP);

extern "C"
{
  SEXP ReporterTable_constructor(SEXP, SEXP);
  SEXP ReporterTable_destructor(SEXP);
  
  SEXP ReporterTable_getDataFrame(SEXP);
  SEXP ReporterTable_trackVariable(SEXP, SEXP);
}

#endif /* RINTERFACE_CHSM_REPORTERTABLE_R_H_ */