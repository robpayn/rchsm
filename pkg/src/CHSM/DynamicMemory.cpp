/*
 * DynamicMemory.cpp
 */

#include "DynamicMemory.h"

DynamicMemory::DynamicMemory(int phase, std::shared_ptr<MemoryFactory> mf) :
  Dynamic(phase),
  memoryFactory_(mf)
{}
