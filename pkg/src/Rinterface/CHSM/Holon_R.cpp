/*
 * Holon_R.cpp
 */

#include "Holon_R.h"
#include "../../CHSM/Value.h"

SEXP Holon_getValueString(SEXP extHolonPtr)
{
  Holon* holonPtr = 
    static_cast <Holon*> (R_ExternalPtrAddr(extHolonPtr));
  
  std::string valueString = holonPtr->value_->toString();

  SEXP valueStringSEXP = mkString(valueString.c_str());

  return valueStringSEXP;
}

SEXP Holon_getVariable(SEXP extHolonPtr, SEXP varName)
{
  Holon* holonPtr = 
    static_cast <Holon*> (R_ExternalPtrAddr(extHolonPtr));
  
  Variable* varPtr = holonPtr->getVariable(CHAR(asChar(varName)));
  
  SEXP extVarPtr = PROTECT(
    R_MakeExternalPtr(varPtr, R_NilValue, R_NilValue)
  );
  UNPROTECT(1);
  
  return extVarPtr;
}
