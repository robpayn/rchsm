/*
 * BehDOConcCell_R.h
 */

#include <R.h>
#include <Rinternals.h>
#include "../conc/BehDOConcCell.h"

extern "C"
{
  SEXP BehDOConcCell_constructor();
  SEXP BehDOConcCell_destructor(SEXP externalPointer);
  SEXP BehDOConcCell_createVariables(SEXP rPointerBeh, SEXP rPointerHolon);
}
