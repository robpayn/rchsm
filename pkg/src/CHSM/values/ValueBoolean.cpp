/**
 * ValueBoolean.cpp
 */

#include "ValueBoolean.h"

ValueBoolean::ValueBoolean(bool value) :
  v_(value)
{}

ValueBoolean::ValueBoolean(std::string valueString)
{
  fromString(valueString);
}

void ValueBoolean::fromString(std::string valueString)
{
  if (valueString.compare("true") == 0) {
    v_ = true;
  } else{
    v_ = false;
  }
}

std::string ValueBoolean::toString()
{
  if (v_) {
    return std::string("true");
  } else{
    return std::string("false");
  }
}
