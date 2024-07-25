/*
 * Cell.cpp
 */

#include "Cell.h"
#include "Bound.h"
#include <sstream>
#include <stdexcept>

Cell::Cell(std::string name) :
  Variable(name),
  Holon(name)
{};

Cell::~Cell() {};

void Cell::addBound(Bound* bound) 
{
  
  if (bounds_.find(bound->name_) == bounds_.end()) {
    bounds_[bound->name_] = bound;
  } else {
    std::ostringstream error;
    error << "Bound name " << bound->name_ << " has already been connected"
        << " to cell " << name_;
    throw error.str();
  }
  
}
