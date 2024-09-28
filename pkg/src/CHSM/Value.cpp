/*
 * Value.cpp
 */

#include "Value.h"
#include "Variable.h"

Value::Value() {}

void Value::setVariable(Variable* variable)
{
  var_ = variable;
}
