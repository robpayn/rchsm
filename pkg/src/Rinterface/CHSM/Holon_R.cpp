/*
 * Holon_R.cpp
 */

#include "Holon_R.h"

SEXP Holon_getValueString(SEXP extHolonPtr)
{
  Holon* holonPtr = 
    static_cast <Holon*> (R_ExternalPtrAddr(extHolonPtr));
  
  std::string valueString = holonPtr->getValueString();

  SEXP valueStringSEXP = mkString(valueString.c_str());

  return valueStringSEXP;
}
