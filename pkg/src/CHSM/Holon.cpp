/*
 * Holon.cpp
 */

#include "Holon.h"
#include "values/ValueVarmap.h"

// Constructors /////////////////////

Holon::Holon(std::string name) :
  Variable(name)
{
  setValue(new ValueVarmap());
}

Holon::Holon(std::string name, ValueVarmap* value) :
  Variable(name, value)
{}


// Methods //////////////////////////

void Holon::addVariable(Variable* var)
{
  try {
    static_cast <ValueVarmap*> (value_)->addVariable(var);
    var->setHolon(this);
  }
  catch (std::runtime_error &thrown) {
    std::ostringstream error;
    error << "Variable map for holon " << name_ << 
      " reported error: " << thrown.what();
    throw std::runtime_error(error.str());
  }
}

Variable* Holon::getVariable(std::string name)
{
  return static_cast <ValueVarmap*> (value_)->getVariable(name);
}
