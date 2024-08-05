/*
 * Model_R.h
 */

#ifndef RCHSM_MODEL_R_H_
#define RCHSM_MODEL_R_H_

#include <R.h>
#include <Rinternals.h>
#include "../Model.h"
#include "../Matrix.h"

void Model_finalizer(SEXP externalPointer);
  
extern "C"
{
  SEXP Model_constructor(SEXP name);
  SEXP Model_destructor(SEXP externalPointer);
  
  SEXP Model_createCell(SEXP extModelPtr, SEXP name, SEXP extHolonPtr);
  SEXP Model_createBound(
    SEXP extModelPtr, 
    SEXP name, 
    SEXP extCellFromPtr, 
    SEXP extCellToPtr,
    SEXP extHolonPtr
  );
}

#endif /* RCHSM_MODEL_R_H_ */
