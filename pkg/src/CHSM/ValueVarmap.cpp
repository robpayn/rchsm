/*
 * ValueVarmap.cpp
 */

#include "ValueVarmap.h"
#include <sstream>
#include <iostream>

ValueVarmap::ValueVarmap()
{}

ValueVarmap::~ValueVarmap()
{}

void ValueVarmap::fromString(std::string valueString)
{
  std::string error = "Not implemented.";
  throw error;
}

std::string ValueVarmap::toString()
{
  std::string error = "Not implemented.";
  throw error;
  return "";
}

void ValueVarmap::addVariable(Variable* var)
{
  if (map_.find(var->name_) == map_.end()) {
    map_[var->name_] = var;
  } else {
    std::ostringstream error;
    error << "Variable name " << var->name_ << " has already been added.";
    throw error.str();
  }
}
