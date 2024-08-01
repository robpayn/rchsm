/*
 * Holon.cpp
 */

#include "Holon.h"
#include <cstring>
#include <sstream>
#include <iostream>

// Constructors /////////////////////

Holon::Holon(std::string name) :
  Variable(name)
{
  value_ = static_cast <Value*> (new ValueVarmap(this));
}


// Destructor ///////////////////////

Holon::~Holon() 
{
  if (value_) {
    static_cast <ValueVarmap*> (value_)->deleteVariables();
  }
  delete value_;
  value_ = nullptr;
}


// Methods //////////////////////////

void Holon::addVariable(Variable* var)
{
  try {
    static_cast <ValueVarmap*> (value_)->addVariable(var);
  }
  catch (std::string* thrownError) {
    std::ostringstream error;
    error << "Variable map for holon " << name_ << 
      " reported error: " << thrownError;
    throw error.str();
  }
  var->setHolon(this);
}
