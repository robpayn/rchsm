/*
 * Variable.cpp
 */

#include "Value.h"
#include "Variable.h"

// Constructors /////////////////////

Variable::Variable(std::string name) :
  name_(name)
{}

Variable::Variable(std::string name, Value* value) :
  name_(name)
{
  setValue(value);
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

void Variable::setValue(Value* value)
{
  value_ = value;
  value_->setVariable(this);
}
