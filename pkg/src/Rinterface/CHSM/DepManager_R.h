/*
 * DepManager_R.h
 */

#ifndef RINTERFACE_CHSM_DEPMANAGER_R_H_
#define RINTERFACE_CHSM_DEPMANAGER_R_H_

#include <R.h>
#include <Rinternals.h>

void DepManInstallOrder_finalizer(SEXP);

extern "C"
{
  SEXP DepManInstallOrder_constructor(SEXP, SEXP);
  SEXP DepManInstallOrder_destructor(SEXP);
}

#endif /* RINTERFACE_CHSM_DEPMANAGER_R_H_ */