/*
 * ValueDouble.cpp
 */

#include "ValueDouble.h"

ValueDouble::ValueDouble() {};

ValueDouble::ValueDouble(double value) : 
  real_(value)
{}

ValueDouble::ValueDouble(std::string valueString)
{
  fromString(valueString);
}

void ValueDouble::fromString(std::string valueString)
{
  real_ = stod(valueString);
}

std::string ValueDouble::toString()
{
  return std::to_string(real_);
}
