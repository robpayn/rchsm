/*
 * Time_R.h
 */

#ifndef RINTERFACE_RESOURCES_TIME_BASIC_TIME_R_H_
#define RINTERFACE_RESOURCES_TIME_BASIC_TIME_R_H_

#include <R.h>
#include <Rinternals.h>

void Time_finalizer(SEXP);

extern "C"
{
  SEXP Time_constructor(SEXP, SEXP, SEXP);
  SEXP Time_destructor(SEXP);
}

#endif /* RINTERFACE_RESOURCES_TIME_BASIC_TIME_R_H_ */
