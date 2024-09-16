/*
 * MemoryDoubleFactory.cpp
 */

#include "MemoryDoubleFactory.h"
#include "MemoryDouble.h"
#include "ValueDouble.h"

#include "iostream"

MemoryDoubleFactory::MemoryDoubleFactory(int size) :
  MemoryFactory(size)
{}

Memory* MemoryDoubleFactory::createMemory(Value* val)
{
  return new MemoryDouble(static_cast<ValueDouble*>(val), size_);
}