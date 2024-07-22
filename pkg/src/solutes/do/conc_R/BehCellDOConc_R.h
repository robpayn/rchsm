/*
 * BehCellDOConc_R.h
 */

#include <R.h>
#include <Rinternals.h>
#include "../conc/BehCellDOConc.h"

extern "C"
{
  SEXP BehCellDOConc_constructor();
  SEXP BehCellDOConc_destructor(SEXP externalPointer);
  SEXP BehCellDOConc_createVariables(SEXP rPointerBeh, SEXP rPointerHolon);
}
