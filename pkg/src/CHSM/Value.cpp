/*
 * Value.cpp
 */

#include "Value.h"
#include "Variable.h"

// Constructors /////////////////////

Value::Value() {}


// Destructor ///////////////////////

Value::~Value() {}

// Methods //////////////////////////

void Value::setVariable(Variable* variable)
{
  var_ = variable;
}
