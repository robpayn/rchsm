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

std::string ValueLong::toString()
{
  return std::to_string(int_);
}
