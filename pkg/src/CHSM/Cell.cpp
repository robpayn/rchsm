/*
 * Cell.cpp
 */

#include "Cell.h"
#include "Bound.h"

Cell::Cell(std::string name) :
  Holon(name)
{}

void Cell::attachBound(Bound* bound) 
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
  
  for(std::pair elem : bounds_) {
    Variable* variable = elem.second->getVariable(name);
    if (variable) {
      map[variable->name_] = variable;
    }
  }
  
  return map;
    
}
