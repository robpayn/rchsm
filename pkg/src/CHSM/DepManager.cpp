/*
 * DepManager.cpp
 */

#include "DepManager.h"
#include "Dynamic.h"

DepManager::DepManager(int numPhases) :
  numPhases_(numPhases)
{
  dynamics_ = new std::list<Dynamic*>[numPhases_];
}

DepManager::~DepManager()
{
  delete []dynamics_;
}

void DepManager::addDynamic(Dynamic* dynamic)
{
  dynamics_[dynamic->phase_].push_back(dynamic);
}

void DepManager::manageDependencies()
{
  
  for(int phase = 0; phase < numPhases_; phase++) {
    for(Dynamic* dynamic : dynamics_[phase]) {
      dynamic->setDependencies(this);
    }
  }
  
}

unsigned int DepManager::size(int phase)
{
  return dynamics_[phase].size();
}
