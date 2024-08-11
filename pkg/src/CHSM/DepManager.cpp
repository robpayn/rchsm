/*
 * DepManager.cpp
 */

#include "DepManager.h"
#include "Dynamic.h"

DepManager::DepManager(int phase) :
  phase_(phase)
{
  dynamics_ = new std::list<Dynamic*>[phase_];
}

DepManager::~DepManager()
{
  delete []dynamics_;
}

void DepManager::addDynamic(Dynamic* dynamic)
{
  dynamics_[dynamic->phase_].push_back(dynamic);
}

unsigned int DepManager::size(int phase)
{
  return dynamics_[phase].size();
}
