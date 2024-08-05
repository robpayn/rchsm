/*
 * Cell.cpp
 */

#include "Cell.h"

Cell::Cell(std::string name) :
  Holon(name)
{}

void Cell::addBound(Bound* bound) 
{
  
  if (bounds_.find(bound->name_) == bounds_.end()) {
    bounds_[bound->name_] = bound;
  } else {
    std::ostringstream error;
    error << "Bound name " << bound->name_ << " has already been connected"
        << " to cell " << name_;
    throw std::runtime_error(error.str());
  }
  
}

std::unordered_map<std::string, Variable*> 
  Cell::getBoundVariables(std::string name)
{
    
  std::unordered_map<std::string, Variable*> map;
  
  std::unordered_map<std::string, Bound*>::iterator iter = bounds_.begin();
  while(iter != bounds_.end()) {
    Variable* variable = iter->second->getVariable(name);
    if (variable) {
      map[variable->name_] = variable;
    }
    iter++;
  }
    
  return map;
    
}
