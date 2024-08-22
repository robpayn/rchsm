/*
 * BehCellTime.h
 */

#ifndef RINTERFACE_RESOURCES_TIME_BASIC_BEHCELLTIME_R_H_
#define RINTERFACE_RESOURCES_TIME_BASIC_BEHCELLTIME_R_H_

#include <R.h>
#include <Rinternals.h>
#include "../../../../resources/time/basic/BehCellTime.h"

extern "C"
{
  SEXP BehCellTime_constructor(SEXP);
  SEXP BehCellTime_destructor(SEXP);
  SEXP BehCellTime_createVariables(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
}

#endif /* RINTERFACE_RESOURCES_TIME_BASIC_BEHCELLTIME_R_H_ */
