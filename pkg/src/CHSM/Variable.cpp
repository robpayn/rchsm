/*
 * Variable.cpp
 */

#include "Variable.h"

// Constructors /////////////////////

Variable::Variable(std::string name) :
  name_(name)
{}

Variable::Variable(std::string name, Value* value) :
  name_(name),
  value_(value)
{
  value_->setVariable(this);
}


// Destructor ///////////////////////

Variable::~Variable() {
  delete value_;
};


// Methods //////////////////////////

void Variable::setHolon(Holon* holon) 
{
  holon_ = holon;
}

// void Variable::setValueFromString(std::string stringValue)
// {
//   value_->fromString(stringValue);
// }
