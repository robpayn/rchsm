/*
 * ValueDoubleMemory.cpp
 */

#include "ValueDoubleMemory.h"
#include "MemoryDouble.h"

ValueDoubleMemory::ValueDoubleMemory(int phase) :
  ValueDouble(),
  DynamicMemory(phase)
{}

ValueDoubleMemory::ValueDoubleMemory(int phase, double init) :
  ValueDouble(init),
  DynamicMemory(phase)
{}

Memory* ValueDoubleMemory::createMemory(int size)
{
  
  return new MemoryDouble(this, size);

}
