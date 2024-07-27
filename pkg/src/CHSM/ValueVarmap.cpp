/*
 * ValueVarmap.cpp
 */

#include "ValueVarmap.h"
#include <sstream>
#include <iostream>

Formatter::Formatter(std::unordered_map<std::string, Variable*>* mapPtr) :
  mapPtr_(mapPtr)
{}

Formatter::~Formatter() {};

FormatterXML::FormatterXML(std::unordered_map<std::string, Variable*>* mapPtr) :
  Formatter(mapPtr)
{}

FormatterXML::~FormatterXML() {};

std::string FormatterXML::format()
{
  std::unordered_map<std::string, Variable*>::iterator iter = mapPtr_->begin();
  
  if (iter != mapPtr_->end()) {
    std::ostringstream stream;
    stream << "\n\n";
    while(iter != mapPtr_->end()) {
      stream << "<Holon name=\"" << iter->first << "\">"
          << iter->second->getValueString()
          << "</Holon>\n";
      iter++;
    }
    stream << "\n";
    return stream.str();
  } else {
    return std::string("");
  }
}

ValueVarmap::ValueVarmap()
{
  formatter_ = new FormatterXML(&map_);
}

ValueVarmap::~ValueVarmap()
{
  delete formatter_;
}

void ValueVarmap::fromString(std::string valueString)
{
  std::string error = "Not implemented.";
  throw error;
}

std::string ValueVarmap::toString()
{
  return formatter_->format();
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

void ValueVarmap::deleteVariables()
{
  std::unordered_map<std::string, Variable*>::iterator iter = map_.begin();
  while (iter != map_.end()) {
    delete iter->second;
    iter++;
  }
}
