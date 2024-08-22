/*
 * Variable_R.cpp
 */

#include "Variable_R.h"
#include "../../CHSM/Variable.h"
#include "../../CHSM/Value.h"

SEXP Variable_getValueString(SEXP extVariablePtr)
{
  Variable* variablePtr = 
    static_cast <Variable*> (R_ExternalPtrAddr(extVariablePtr));
  
  std::string valueString = variablePtr->value_->toString();
  
  SEXP valueStringSEXP = mkString(valueString.c_str());
  
  return valueStringSEXP;
}
