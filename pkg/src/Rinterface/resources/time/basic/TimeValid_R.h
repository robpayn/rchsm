/*
 * TimeValid_R.h
 */

#ifndef RINTERFACE_RESOURCES_TIME_BASIC_TIMEVALID_R_H_
#define RINTERFACE_RESOURCES_TIME_BASIC_TIMEVALID_R_H_

#include <R.h>
#include <Rinternals.h>

void TimeValid_finalizer(SEXP);

extern "C"
{
  SEXP TimeValid_constructor(SEXP, SEXP, SEXP);
  SEXP TimeValid_destructor(SEXP);
}

#endif /* RINTERFACE_RESOURCES_TIME_BASIC_TIMEVALID_R_H_ */
