/*
 * ValueVarmap.cpp
 */

#include "ValueVarmap.h"
#include "../Variable.h"
#include "../Holon.h"
#include "StateDouble.h"

// #include <iostream>

// Constructors /////////////////////

ValueVarmap::ValueVarmap()
{
  formatter_ = new VarmapFormatterXML(this);
}


// Destructor ///////////////////////

ValueVarmap::~ValueVarmap()
{
  for(std::pair elem : map_) {
    delete elem.second;
    elem.second = nullptr;
  }
  
  delete formatter_;
}


// Methods //////////////////////////

void ValueVarmap::addVariable(Variable* var)
{
  if (map_.find(var->name_) == map_.end()) {
    map_[var->name_] = var;
    var->setHolon(dynamic_cast<Holon*>(var_));
  } else {
    std::ostringstream error;
    error << "Variable name " << var->name_ << " has already been added.";
    throw std::runtime_error(error.str());
  }
}

void ValueVarmap::fromString(std::string valueString)
{
  std::string error = "Not implemented.";
  throw std::runtime_error(error);
}

Variable* ValueVarmap::getVariable(std::string name)
{
  std::unordered_map<std::string, Variable*>::iterator iter = map_.find(name);
  if (iter == map_.end()) {
    return nullptr;
  } else {
    return iter->second;
  }
}

std::string ValueVarmap::toString()
{
  return formatter_->format();
}

VarmapFormatter::VarmapFormatter(ValueVarmap* varmap) :
  varmap_(varmap)
{}

VarmapFormatter::~VarmapFormatter() {};

VarmapFormatterXML::VarmapFormatterXML(ValueVarmap* varmap) :
  VarmapFormatter(varmap)
{}

std::string VarmapFormatterXML::format()
{

  int depth = 0;
  Variable* layer = varmap_->var_;
  while (layer->holon_) {
    depth++;
    layer = static_cast <Variable*> (layer->holon_);
  }

  std::string indent = std::string(2 * depth, ' ');

  if (varmap_->map_.size() > 0) {
    std::ostringstream stream;
    stream << "\n";
    
    for(std::pair elem : varmap_->map_) {
      Holon* holon = dynamic_cast <Holon*> (elem.second);
      std::string typeName;
      if (holon) {
        typeName = std::string("Holon");
      } else {
        typeName = std::string("Variable");
      }
      stream << 
        indent <<
          "<" << typeName << " " <<
            "name=\"" << elem.first << "\"" <<
          ">" <<
          elem.second->value_->toString();
          if (
              holon && 
                static_cast <ValueVarmap*> (holon->value_)->map_.size() > 0
          ) {
            stream << indent;
          }
          stream << "</" << typeName << ">\n";
    }
    
    return stream.str();
  } else {
    return std::string("");
  }
}

