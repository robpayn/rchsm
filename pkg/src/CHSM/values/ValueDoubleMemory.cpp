/*
 * ValueDoubleMemory.cpp
 */

#include "ValueDoubleMemory.h"
#include "MemoryDouble.h"

ValueDoubleMemory::ValueDoubleMemory(
  double init,
  int phase, 
  std::shared_ptr<MemoryFactory> mf
) :
  ValueDouble(init),
  DynamicMemory(phase, mf)
{}
