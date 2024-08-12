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

void DepManager::createDependency(Value* depVal, Value* neededVal)
{}

void DepManager::manageDependencies()
{
  
  std::list<Dynamic*>::iterator iter;
  for(int phase = 0; phase < numPhases_; phase++) {
    iter = dynamics_[phase].begin();
    while(iter != dynamics_[phase].end()) {
      (*iter)->setDependencies(this);
      iter++;
    }
  }
  
}

unsigned int DepManager::size(int phase)
{
  return dynamics_[phase].size();
}
