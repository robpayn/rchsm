/*
 * ValueLong.cpp
 */

#include "ValueLong.h"

ValueLong::ValueLong() {}

ValueLong::ValueLong(long value) : 
  int_(value)
{}

ValueLong::ValueLong(std::string valueString)
{
  fromString(valueString);
}

void ValueLong::fromString(std::string valueString)
{
  int_ = stol(valueString);
}

bool ValueLong::isDefined()
{
  return !(int_ == LONG_MIN);
}

std::string ValueLong::toString()
{
  if (isDefined()) {
    return std::to_string(int_);
  } else {
    return std::string("Undefined");
  }
}
