/**
 * ValueBoolean.cpp
 */

#include "ValueBoolean.h"

ValueBoolean::ValueBoolean(bool value)
{
  setValue(value);
}

ValueBoolean::ValueBoolean(std::string valueString)
{
  fromString(valueString);
}

void ValueBoolean::fromString(std::string valueString)
{
  if (valueString.compare("true") == 0) {
    setValue(true);
  } else{
    setValue(false);
  }
}

void ValueBoolean::setValue(bool value)
{
  v_ = value;
  isDefined_ = true;
}

std::string ValueBoolean::toString()
{
  if (v_) {
    return std::string("true");
  } else{
    return std::string("false");
  }
}
