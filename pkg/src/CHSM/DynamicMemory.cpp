/*
 * DynamicMemory.cpp
 */

#include "DynamicMemory.h"
#include "Memory.h"

DynamicMemory::DynamicMemory(int phase) :
  Dynamic(phase)
{}

DynamicMemory::~DynamicMemory()
{
  delete memory_;
}

void DynamicMemory::attachMemory(Memory* memory)
{
  memory_ = memory;
}
