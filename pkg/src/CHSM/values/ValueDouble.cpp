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

ValueDouble::~ValueDouble()
{}

void ValueDouble::fromString(std::string valueString)
{
  real_ = stod(valueString);
}

bool ValueDouble::isDefined()
{
  return !std::isnan(real_);
}

std::string ValueDouble::toString()
{
  if(isDefined()) {
    return std::to_string(real_);
  } else {
    return std::string("Undefined");
  }
}
