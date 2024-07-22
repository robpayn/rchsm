/*
 * Variable.cpp
 */

#include <string>
#include "Variable.h"

Variable::Variable() {};

Variable::Variable(std::string name) :
  name_(name)
{};

Variable::~Variable() {};

// Variable::Variable(std::string name, void* value, void* holon) :
//   name_(name),
//   value_(static_cast <Value*> (value)),
//   holon_(static_cast <Holon*> (holon))
// {}

// void Variable::setValueFromString(std::string stringValue)
// {
//   value_->fromString(stringValue);
// }

// std::string Variable::getValueAsString()
// {
//   return value_->toString();
// }