/*
 * ValueLongMemory.cpp
 */

#include "ValueLongMemory.h"
#include "MemoryLong.h"

ValueLongMemory::ValueLongMemory(
  long init, 
  int phase
) :
  ValueLong(init),
  DynamicMemory(phase)
{}
