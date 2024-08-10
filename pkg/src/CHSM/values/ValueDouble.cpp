/*
 * ValueDouble.cpp
 */

#include "ValueDouble.h"

ValueDouble::ValueDouble() {};

ValueDouble::ValueDouble(double value) :
  v_(value)
{}

ValueDouble::ValueDouble(std::string valueString)
{
  fromString(valueString);
}

ValueDouble::~ValueDouble()
{}

void ValueDouble::fromString(std::string valueString)
{
  v_ = stod(valueString);
}

bool ValueDouble::isDefined()
{
  return !std::isnan(v_);
}

std::string ValueDouble::toString()
{
  if(isDefined()) {
    return std::to_string(v_);
  } else {
    return std::string("Undefined");
  }
}
