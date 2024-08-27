/*
 * Bound.cpp
 */

#include "Bound.h"
#include "Cell.h"

Bound::Bound(std::string name) :
  Holon(name)
{}

Bound::Bound(std::string name, Cell* cellFrom, Cell* cellTo) :
  Holon(name),
  cellFrom_(cellFrom),
  cellTo_(cellTo)
{
  if (cellFrom_ != nullptr) {
    cellFrom_->attachBound(this);
  }
  if (cellTo_ != nullptr) {
    cellTo_->attachBound(this);
  }
}
