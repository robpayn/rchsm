/*
 * Holon.cpp
 */

#include "Holon.h"

// Constructors /////////////////////

Holon::Holon(std::string name) :
  Variable(name)
{
  value_ = static_cast <Value*> (new ValueVarmap(this));
}


// Methods //////////////////////////

void Holon::addVariable(Variable* var)
{
  try {
    static_cast <ValueVarmap*> (value_)->addVariable(var);
  }
  catch (std::runtime_error &thrown) {
    std::ostringstream error;
    error << "Variable map for holon " << name_ << 
      " reported error: " << thrown.what();
    throw std::runtime_error(error.str());
  }
  var->setHolon(this);
}

Variable* Holon::getVariable(std::string name)
{
  return static_cast <ValueVarmap*> (value_)->getVariable(name);
}
