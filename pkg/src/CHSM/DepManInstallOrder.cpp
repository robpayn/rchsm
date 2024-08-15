/*
 * DepManInstallOrder.cpp
 */

#include "DepManInstallOrder.h"

DepManInstallOrder::DepManInstallOrder(int numPhases) :
  DepManager(numPhases)
{}

void DepManInstallOrder::createDependency(Value* depVal, Value* neededVal)
{}

std::vector<Dynamic*> DepManInstallOrder::sort(int phase)
{
  
  std::vector<Dynamic*> vec(dynamics_[phase].size());
  
  long index = 0;
  for(Dynamic* dyn : dynamics_[phase]) {
    vec[index] = dyn;
    index++;
  }
  
  return vec;
  
}
