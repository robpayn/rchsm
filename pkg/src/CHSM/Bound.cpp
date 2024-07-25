/*
 * Bound.cpp
 */

#include "Bound.h"
#include "Cell.h"

Bound::Bound(std::string name) :
  Variable(name),
  Holon(name)
{};

Bound::Bound(std::string name, Cell* cellFrom, Cell* cellTo) :
  Variable(name),
  Holon(name),
  cellFrom_(cellFrom),
  cellTo_(cellTo)
{
  
  if (cellFrom_ != nullptr) {
    cellFrom_->addBound(this);
  }
  if (cellTo_ != nullptr) {
    cellTo_->addBound(this);
  }
  
};
  
Bound::~Bound() {};
