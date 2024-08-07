/*
 * BehCellTime.h
 */

#ifndef RESOURCES_TIME_BASIC_BEHCELLTIME_R_H_
#define RESOURCES_TIME_BASIC_BEHCELLTIME_R_H_

#include <R.h>
#include <Rinternals.h>
#include "../../../../resources/time/basic/BehCellTime.h"

extern "C"
{
  SEXP BehCellTime_constructor();
  SEXP BehCellTime_destructor(SEXP);
  SEXP BehCellTime_createVariables(SEXP, SEXP, SEXP);
}

#endif /* RESOURCES_TIME_BASIC_BEHCELLTIME_R_H_ */
