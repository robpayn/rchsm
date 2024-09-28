/*
 * DepManInstallOrder.cpp
 */

#include "DepManInstallOrder.h"

DepManInstallOrder::DepManInstallOrder(int numPhases) :
  DepManager(numPhases)
{}

void DepManInstallOrder::createDependency(Value* depVal, Value* neededVal)
{}

std::vector<Updater*> DepManInstallOrder::sort(int phase)
{
  std::vector<Updater*> vec(updaters_[phase].size());
  
  long index = 0;
  for(Updater* updater : updaters_[phase]) {
    vec[index] = updater;
    index++;
  }
  
  return vec;
}
