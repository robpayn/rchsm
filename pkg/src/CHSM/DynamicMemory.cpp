/*
 * DynamicMemory.cpp
 */

#include "DynamicMemory.h"
#include "Memory.h"

DynamicMemory::DynamicMemory() :
  Dynamic()
{}

DynamicMemory::~DynamicMemory()
{
  delete memory_;
}

void DynamicMemory::attachMemory(Memory* memory)
{
  memory_ = memory;
  memory_->attachDynamicValue(this);
}
