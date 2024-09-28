/*
 * DepManager.cpp
 */

#include "DepManager.h"
#include "Updater.h"

DepManager::DepManager(int numPhases) :
  numPhases_(numPhases)
{
  updaters_ = new std::list<Updater*>[numPhases_];
}

DepManager::~DepManager()
{
  delete []updaters_;
}

void DepManager::addUpdater(Updater* updater)
{
  updaters_[updater->phase_].push_back(updater);
}

void DepManager::manageDependencies()
{
  for(int phase = 0; phase < numPhases_; phase++) {
    for(Updater* updater : updaters_[phase]) {
      updater->setDependencies(*this);
    }
  }
}

unsigned int DepManager::size(int phase)
{
  return updaters_[phase].size();
}
