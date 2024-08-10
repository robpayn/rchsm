/*
 * Machine_R.h
 */

#ifndef CHSM_MACHINE_R_H_
#define CHSM_MACHINE_R_H_

#include <R.h>
#include <Rinternals.h>
#include "../Machine.h"
#include "../Matrix.h"

void Machine_finalizer(SEXP externalPointer);
  
extern "C"
{
  SEXP Machine_constructor(SEXP);
  SEXP Machine_destructor(SEXP);
  
  SEXP Machine_createBound(SEXP, SEXP, SEXP, SEXP, SEXP);
  SEXP Machine_createCell(SEXP, SEXP, SEXP);
  SEXP Machine_init(SEXP);
  SEXP Machine_run(SEXP);
}

#endif /* CHSM_MACHINE_R_H_ */
