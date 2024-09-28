/*
 * MemoryDoubleFactory.cpp
 */

#include "MemoryDoubleFactory.h"
#include "MemoryDouble.h"
#include "../DynamicMemory.h"

#include "iostream"

MemoryDoubleFactory::MemoryDoubleFactory(int size) :
  MemoryFactory(size)
{}

Memory* MemoryDoubleFactory::createMemory(DynamicMemory* dm)
{
  Memory* memory = new MemoryDouble(size_);
  dm->attachMemory(memory);
  return memory;
}
