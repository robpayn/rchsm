/*
 * Matrix_R.cpp
 */

#include "Matrix_R.h"
#include "../Matrix.h"
#include <exception>
#include <sstream>

void Matrix_finalizer(SEXP externalPointer) 
{
  Matrix* pointer = 
    static_cast <Matrix*> (R_ExternalPtrAddr(externalPointer));
  R_ClearExternalPtr(externalPointer);
  delete pointer;
}

SEXP Matrix_destructor(SEXP externalPointer) 
{
  Matrix_finalizer(externalPointer);
  return R_NilValue;
}

SEXP Matrix_constructor(
  SEXP extDepManagerPtr,
  SEXP regFinalizer
) 
{
  try {
    
    DepManager* dmPtr = 
      static_cast <DepManager*> (R_ExternalPtrAddr(extDepManagerPtr));
    
    Matrix* pointer = new Matrix(dmPtr);
    
    SEXP externalPointer = PROTECT(
      R_MakeExternalPtr(pointer, R_NilValue, R_NilValue)
    );
    
    if(asLogical(regFinalizer)) {
      R_RegisterCFinalizer(externalPointer, Matrix_finalizer);
    }
    
    UNPROTECT(1);
    
    return externalPointer;
    
  } catch (std::runtime_error &thrown) {
    
    std::ostringstream error;
    error << "<CERROR>\n" << thrown.what();
    return mkString(error.str().c_str());
    
  }
}

SEXP Matrix_createBound(
  SEXP extMatrixPtr, 
  SEXP name, 
  SEXP extCellFromPtr, 
  SEXP extCellToPtr,
  SEXP extHolonPtr
) 
{
  try {
    
    Matrix* matrixPtr = 
      static_cast <Matrix*> (R_ExternalPtrAddr(extMatrixPtr));
    
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
    
    Bound* boundPtr = matrixPtr->createBound(
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
    
    std::ostringstream error;
    error << "<CERROR>\n" << thrown.what();
    return mkString(error.str().c_str());
    
  }
}

SEXP Matrix_createCell(SEXP extMatrixPtr, SEXP name, SEXP extHolonPtr) 
{
  
  Matrix* matrixPtr = 
    static_cast <Matrix*> (R_ExternalPtrAddr(extMatrixPtr));
  
  Holon* holonPtr;
  if (extHolonPtr == R_NilValue) {
    holonPtr = nullptr;
  } else {
    holonPtr = static_cast <Holon*> (R_ExternalPtrAddr(extHolonPtr));
  }
  
  Cell* cellPtr = matrixPtr->createCell(
    CHAR(asChar(name)), 
    holonPtr
  );
  
  SEXP extCellPtr = PROTECT(
    R_MakeExternalPtr(cellPtr, R_NilValue, R_NilValue)
  );
  UNPROTECT(1);
  
  return extCellPtr;
  
}

SEXP Matrix_createVariable(
  SEXP extMatrixPtr, 
  SEXP name, 
  SEXP extValuePtr, 
  SEXP extHolonPtr
)
{
  try {
    
    Matrix* matrixPtr =
      static_cast<Matrix*>(R_ExternalPtrAddr(extMatrixPtr));
    Value* valuePtr =
      static_cast<Value*>(R_ExternalPtrAddr(extValuePtr));
    Holon* holonPtr =
      static_cast<Holon*>(R_ExternalPtrAddr(extHolonPtr));
    
    Variable* varPtr = matrixPtr->createVariable(
      CHAR(asChar(name)),
      valuePtr,
      *holonPtr
    );
    
    SEXP extVarPtr = PROTECT(
      R_MakeExternalPtr(varPtr, R_NilValue, R_NilValue)
    );
    UNPROTECT(1);
    
    return extVarPtr;
    
  } catch (std::runtime_error &thrown) {
    
    std::ostringstream error;
    error << "<CERROR>\n" << thrown.what();
    return mkString(error.str().c_str());
    
  }
}

SEXP Matrix_installSolver(SEXP extMatrixPtr, SEXP extSolverPtr)
{
  Matrix* matrixPtr =
    static_cast<Matrix*>(R_ExternalPtrAddr(extMatrixPtr));
  Solver* solverPtr =
    static_cast<Solver*>(R_ExternalPtrAddr(extSolverPtr));
  
  matrixPtr->installSolver(solverPtr);
  
  return R_NilValue;
}
