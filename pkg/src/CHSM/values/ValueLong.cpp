/*
 * ValueLong.cpp
 */

#include "ValueLong.h"

ValueLong::ValueLong() {}

ValueLong::ValueLong(long value) : 
  v_(value)
{}

ValueLong::ValueLong(std::string valueString)
{
  fromString(valueString);
}

void ValueLong::fromString(std::string valueString)
{
  v_ = stol(valueString);
}

bool ValueLong::isDefined()
{
  return !(v_ == LONG_MIN);
}

std::string ValueLong::toString()
{
  if (isDefined()) {
    return std::to_string(v_);
  } else {
    return std::string("Undefined");
  }
}
