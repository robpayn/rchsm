/*
 * ValueBooleanMemory.cpp
 */

#include "ValueBooleanMemory.h"
#include "MemoryBoolean.h"

ValueBooleanMemory::ValueBooleanMemory(int phase) :
  ValueBoolean(),
  DynamicMemory(phase)
{}

ValueBooleanMemory::ValueBooleanMemory(int phase, bool init) :
  ValueBoolean(init),
  DynamicMemory(phase)
{}

Memory* ValueBooleanMemory::createMemory(int size)
{
  
  return new MemoryBoolean(this, size);
  
}
