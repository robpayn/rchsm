/*
 * MemoryDoubleFactory_R.h
 */

#ifndef RINTERFACE_CHSM_MEMORYDOUBLEFACTORY_R_H_
#define RINTERFACE_CHSM_MEMORYDOUBLEFACTORY_R_H_

#include <R.h>
#include <Rinternals.h>

void MemoryDoubleFactory_finalizer(SEXP);

extern "C"
{
  SEXP MemoryDoubleFactory_constructor(SEXP, SEXP);
  SEXP MemoryDoubleFactory_destructor(SEXP);
}

#endif /* RINTERFACE_CHSM_MEMORYDOUBLEFACTORY_R_H_ */
