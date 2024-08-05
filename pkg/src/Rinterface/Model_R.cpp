/*
 * Model_R.cpp
 */

#include "Model_R.h"

void Model_finalizer(SEXP externalPointer) 
{
  
  Model* pointer = static_cast <Model*> (R_ExternalPtrAddr(externalPointer));
  R_ClearExternalPtr(externalPointer);
  delete pointer;
  
}

SEXP Model_destructor(SEXP externalPointer) 
{
  
  Model_finalizer(externalPointer);
  
  return R_NilValue;
  
}

SEXP Model_constructor(SEXP name) 
{
  try {
    
    Model* pointer = new Model(CHAR(asChar(name)), new Matrix());
  
    SEXP externalPointer = PROTECT(
      R_MakeExternalPtr(pointer, R_NilValue, R_NilValue)
    );
    
    R_RegisterCFinalizer(externalPointer, Model_finalizer);
    
    UNPROTECT(1);
    
    return externalPointer;
    
  } catch (std::runtime_error &thrown) {
    
    return mkString(thrown.what());
    
  }
}

SEXP Model_createCell(SEXP extModelPtr, SEXP name, SEXP extHolonPtr) 
{
  
  Model* modelPtr = static_cast <Model*> (R_ExternalPtrAddr(extModelPtr));
  
  Holon* holonPtr;
  if (extHolonPtr == R_NilValue) {
    holonPtr = nullptr;
  } else {
    holonPtr = static_cast <Holon*> (R_ExternalPtrAddr(extHolonPtr));
  }
  
  Cell* cellPtr = modelPtr->createCell(
    CHAR(asChar(name)), 
    holonPtr
  );

  SEXP extCellPtr = PROTECT(
    R_MakeExternalPtr(cellPtr, R_NilValue, R_NilValue)
  );
  UNPROTECT(1);

  return extCellPtr;

}

SEXP Model_createBound(
    SEXP extModelPtr, 
    SEXP name, 
    SEXP extCellFromPtr, 
    SEXP extCellToPtr,
    SEXP extHolonPtr
) 
{
  try {
    
    Model* modelPtr = static_cast <Model*> (R_ExternalPtrAddr(extModelPtr));
    
    Cell* cellFromPtr;
    if (extCellFromPtr == R_NilValue) {
      cellFromPtr = nullptr;
    } else {
      cellFromPtr = static_cast <Cell*> (R_ExternalPtrAddr(extCellFromPtr));
    }
    
    Cell* cellToPtr;
    if (extCellToPtr == R_NilValue) {
      cellToPtr = nullptr;
    } else {
      cellToPtr = static_cast <Cell*> (R_ExternalPtrAddr(extCellToPtr));
    }
    
    Holon* holonPtr;
    if (extHolonPtr == R_NilValue) {
      holonPtr = nullptr;
    } else {
      holonPtr = static_cast <Holon*> (R_ExternalPtrAddr(extHolonPtr));
    }
    
    Bound* boundPtr = modelPtr->createBound(
      CHAR(asChar(name)), 
      cellFromPtr, 
      cellToPtr, 
      holonPtr
    );
  
    SEXP extBoundPtr = PROTECT(
      R_MakeExternalPtr(boundPtr, R_NilValue, R_NilValue)
    );
    UNPROTECT(1);
    return extBoundPtr;
    
  } catch (std::runtime_error &thrown) {
    
    return mkString(thrown.what());
    
  }

}
