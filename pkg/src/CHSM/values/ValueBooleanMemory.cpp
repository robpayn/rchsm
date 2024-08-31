/*
 * ValueBooleanMemory.cpp
 */

#include "ValueBooleanMemory.h"
#include "MemoryBoolean.h"

ValueBooleanMemory::ValueBooleanMemory(
  bool init,
  int phase, 
  std::shared_ptr<MemoryFactory> mf
) :
  ValueBoolean(init),
  DynamicMemory(phase, mf)
{}
