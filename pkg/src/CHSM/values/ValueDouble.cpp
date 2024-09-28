/*
 * ValueDouble.cpp
 */

#include "ValueDouble.h"

ValueDouble::ValueDouble(double value) :
  v_(value)
{}

ValueDouble::ValueDouble(std::string valueString)
{
  fromString(valueString);
}

void ValueDouble::fromString(std::string valueString)
{
  v_ = stod(valueString);
}

std::string ValueDouble::toString()
{
  return std::to_string(v_);
}
