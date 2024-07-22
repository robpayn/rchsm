/*
 * Bound.cpp
 */

#include "Bound.h"
#include "Cell.h"

Bound::Bound(std::string name) :
  Holon(name)
{};

Bound::Bound(std::string name, Cell* fromCell, Cell* toCell) :
  Holon(name),
  cellFrom_(fromCell),
  cellTo_(toCell)
{
  if (cellFrom_ != nullptr) {
    cellFrom_->addBound(this);
  }
  if (cellTo_ != nullptr) {
    cellTo_->addBound(this);
  }
};
  
Bound::~Bound() {};
