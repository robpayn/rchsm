/*
 * Variable.cpp
 */

#include <string>
#include "Variable.h"

// Constructors /////////////////////

Variable::Variable(std::string name) :
  name_(name)
{};

// Destructor ///////////////////////

Variable::~Variable() {};

// Methods //////////////////////////

void Variable::setHolon(Holon* holon) 
{
  holon_ = holon;
}

std::string Variable::getValueString()
{
  return value_->toString();
}

// void Variable::setValueFromString(std::string stringValue)
// {
//   value_->fromString(stringValue);
// }
