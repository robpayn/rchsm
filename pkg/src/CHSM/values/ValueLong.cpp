/*
 * ValueLong.cpp
 */

#include "ValueLong.h"

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

std::string ValueLong::toString()
{
  return std::to_string(v_);
}
