/*
 * ValueLongMemory.cpp
 */

#include "ValueLongMemory.h"
#include "MemoryLong.h"

ValueLongMemory::ValueLongMemory(
  long init, 
  int phase, 
  std::shared_ptr<MemoryFactory> mf
) :
  ValueLong(init),
  DynamicMemory(phase, mf)
{}
