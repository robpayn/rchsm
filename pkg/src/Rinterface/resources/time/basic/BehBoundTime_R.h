/*
 * BehBoundTime_R.h
 */

#ifndef RESOURCES_TIME_BASIC_BEHBOUNDTIME_R_H_
#define RESOURCES_TIME_BASIC_BEHBOUNDTIME_R_H_

#include <R.h>
#include <Rinternals.h>
#include "../../../../resources/time/basic/BehBoundTime.h"

extern "C"
{
  SEXP BehBoundTime_constructor();
  SEXP BehBoundTime_destructor(SEXP);
  SEXP BehBoundTime_createVariables(SEXP, SEXP, SEXP);
}


#endif /* RESOURCES_TIME_BASIC_BEHBOUNDTIME_R_H_ */
