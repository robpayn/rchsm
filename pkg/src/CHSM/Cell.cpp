/*
 * Cell.cpp
 */

#include "Cell.h"
#include "Bound.h"

Cell::Cell(std::string name) :
  Holon(name)
{};

Cell::~Cell() {};

void Cell::addBound(Bound* bound) {
  if (bounds_.find(bound->name_) == bounds_.end()) {
    bounds_[bound->name_] = bound;
  } else {
    std::ostringstream error;
    error << "Bound name " << bound->name_ << " has already been added " <<
      "to cell " << name_;
    throw error.str();
  }
}
