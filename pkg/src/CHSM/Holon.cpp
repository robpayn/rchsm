/*
 * Holon.cpp
 */

#include "Holon.h"
#include <cstring>
#include <sstream>
#include <iostream>

// Constructors/Destructor

Holon::Holon(std::string name) :
  Variable(name)
{
  varMap_ = new ValueVarmap();
  value_ = dynamic_cast <Value*> (varMap_);
};

Holon::~Holon() {};

// Methods

void Holon::addVariable(Variable* var)
{
  try {
    varMap_->addVariable(var);
  }
  catch (std::string* thrownError) {
    std::ostringstream error;
    error << "Variable map for holon " << name_ << " reported error: " << thrownError;
    throw error.str();
  }
}
