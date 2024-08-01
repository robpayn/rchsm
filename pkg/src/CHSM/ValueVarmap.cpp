/*
 * ValueVarmap.cpp
 */

#include "ValueVarmap.h"
#include <sstream>
#include <iostream>
#include <typeinfo>
#include "Holon.h"

VarmapFormatter::VarmapFormatter(
  std::unordered_map<std::string, Variable*>* mapPtr
) :
  mapPtr_(mapPtr)
{}

VarmapFormatter::~VarmapFormatter() {};

VarmapFormatterXML::VarmapFormatterXML(
  std::unordered_map<std::string, Variable*>* mapPtr,
  Variable* variable
) :
  VarmapFormatter(mapPtr),
  variable_(variable)
{}

VarmapFormatterXML::~VarmapFormatterXML() {};

std::string VarmapFormatterXML::format()
{
  std::unordered_map<std::string, Variable*>::iterator iter = mapPtr_->begin();
  
  int depth = 0;
  Variable* layer = variable_;
  while (layer->holon_ != nullptr) {
    depth++;
    layer = static_cast <Variable*> (layer->holon_);
  }
  
  std::string indent = std::string(2 * depth, ' ');

  if (iter != mapPtr_->end()) {
    std::ostringstream stream;
    stream << "\n";
    while(iter != mapPtr_->end()) {
      std::string typeName;
      if (dynamic_cast <Holon*> (iter->second)) {
        typeName = std::string("Holon");
      } else {
        typeName = std::string("Variable");
      }
      stream << indent
          << "<" << typeName << " name=\"" << iter->first << "\">"
          << iter->second->getValueString()
          << "</" << typeName << ">\n";
      iter++;
    }
    return stream.str();
  } else {
    return std::string("");
  }
}

// Constructors /////////////////////

ValueVarmap::ValueVarmap(Variable* variable)
{
  formatter_ = new VarmapFormatterXML(&map_, variable);
}


// Destructor ///////////////////////

ValueVarmap::~ValueVarmap()
{
  deleteVariables();
  delete formatter_;
  formatter_ = nullptr;
}


// Methods //////////////////////////

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
    iter->second = nullptr;
    iter++;
  }
  map_.erase(map_.begin(), map_.end());
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
