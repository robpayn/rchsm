/*
 * Machine_R.cpp
 */

#include "Machine_R.h"

void Machine_finalizer(SEXP externalPointer) 
{
  
  Machine* pointer = 
    static_cast <Machine*> (R_ExternalPtrAddr(externalPointer));
  R_ClearExternalPtr(externalPointer);
  delete pointer;
  
}

SEXP Machine_destructor(SEXP externalPointer) 
{
  
  Machine_finalizer(externalPointer);
  
  return R_NilValue;
  
}

SEXP Machine_constructor(SEXP name) 
{
  try {
    
    Machine* pointer = new Machine(CHAR(asChar(name)));
  
    SEXP externalPointer = PROTECT(
      R_MakeExternalPtr(pointer, R_NilValue, R_NilValue)
    );
    
    R_RegisterCFinalizer(externalPointer, Machine_finalizer);
    
    UNPROTECT(1);
    
    return externalPointer;
    
  } catch (std::runtime_error &thrown) {
    
    return mkString(thrown.what());
    
  }
}

SEXP Machine_createCell(SEXP extMachinePtr, SEXP name, SEXP extHolonPtr) 
{
  
  Machine* machinePtr = 
    static_cast <Machine*> (R_ExternalPtrAddr(extMachinePtr));
  
  Holon* holonPtr;
  if (extHolonPtr == R_NilValue) {
    holonPtr = nullptr;
  } else {
    holonPtr = static_cast <Holon*> (R_ExternalPtrAddr(extHolonPtr));
  }
  
  Cell* cellPtr = machinePtr->createCell(
    CHAR(asChar(name)), 
    holonPtr
  );

  SEXP extCellPtr = PROTECT(
    R_MakeExternalPtr(cellPtr, R_NilValue, R_NilValue)
  );
  UNPROTECT(1);

  return extCellPtr;

}

SEXP Machine_createBound(
    SEXP extMachinePtr, 
    SEXP name, 
    SEXP extCellFromPtr, 
    SEXP extCellToPtr,
    SEXP extHolonPtr
) 
{
  try {
    
    Machine* machinePtr = 
      static_cast <Machine*> (R_ExternalPtrAddr(extMachinePtr));
    
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
    
    Bound* boundPtr = machinePtr->createBound(
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
