/*
 * ValueBooleanMemory.cpp
 */

#include "ValueBooleanMemory.h"
#include "MemoryBoolean.h"

ValueBooleanMemory::ValueBooleanMemory(
  bool init,
  int phase
) :
  ValueBoolean(init),
  DynamicMemory(phase)
{}
