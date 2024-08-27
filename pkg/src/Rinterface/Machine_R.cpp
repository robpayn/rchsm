/*
 * Machine_R.cpp
 */

#include "Machine_R.h"
#include "../Machine.h"

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

SEXP Machine_constructor(
  SEXP name, 
  SEXP extMatrixPtr,
  SEXP regFinalizer
) 
{
  try {
    
    Matrix* matrixPtr = 
      static_cast <Matrix*> (R_ExternalPtrAddr(extMatrixPtr));
    
    Machine* pointer = new Machine(CHAR(asChar(name)), matrixPtr);
  
    SEXP externalPointer = PROTECT(
      R_MakeExternalPtr(pointer, R_NilValue, R_NilValue)
    );
    
    if(asLogical(regFinalizer)) {
      R_RegisterCFinalizer(externalPointer, Machine_finalizer);
    }
    
    UNPROTECT(1);
    
    return externalPointer;
    
  } catch (std::runtime_error &thrown) {
    
    std::ostringstream error;
    error << "<CERROR>\n" << thrown.what();
    return mkString(error.str().c_str());
    
  }
}

SEXP Machine_installReporter(SEXP extMachinePtr, SEXP extReporterPtr)
{
  try {
    
    Machine* machinePtr =
      static_cast<Machine*>(R_ExternalPtrAddr(extMachinePtr));
    Reporter* reporterPtr =
      static_cast<Reporter*>(R_ExternalPtrAddr(extReporterPtr));
    machinePtr->installReporter(reporterPtr);
    
  } catch (std::runtime_error &thrown) {
    
    std::ostringstream error;
    error << "<CERROR>\n" << thrown.what();
    return mkString(error.str().c_str());
    
  }
  
  return R_NilValue;
}

SEXP Machine_run(SEXP extMachinePtr)
{
  try {
    
    Machine* machinePtr =
      static_cast <Machine*> (R_ExternalPtrAddr(extMachinePtr));
    machinePtr->run();
    
  } catch (std::runtime_error &thrown) {
    
    std::ostringstream error;
    error << "<CERROR>\n" << thrown.what();
    return mkString(error.str().c_str());
    
  }
  
  return R_NilValue;
}

SEXP Machine_setTimeValidVariable(SEXP extMachinePtr, SEXP extVarPtr)
{
  try {

    Machine* machinePtr =
      static_cast<Machine*>(R_ExternalPtrAddr(extMachinePtr));
    Variable* varPtr =
      static_cast<Variable*>(R_ExternalPtrAddr(extVarPtr));
    machinePtr->setTimeValidVariable(varPtr);
    
  } catch (std::runtime_error &thrown) {

    std::ostringstream error;
    error << "<CERROR>\n" << thrown.what();
    return mkString(error.str().c_str());

  }
  
  return R_NilValue;
}
