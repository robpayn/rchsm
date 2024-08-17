/*
 * ValueLongMemory.cpp
 */

#include "ValueLongMemory.h"
#include "MemoryLong.h"

ValueLongMemory::ValueLongMemory(int phase) :
  ValueLong(),
  DynamicMemory(phase)
{}

ValueLongMemory::ValueLongMemory(int phase, long init) :
  ValueLong(init),
  DynamicMemory(phase)
{}

Memory* ValueLongMemory::createMemory(int size)
{
  
  return new MemoryLong(this, size);
  
}
