/*
 * MemoryLong.cpp
 */

#include "MemoryLong.h"
#include "ValueLong.h"
#include "../DynamicMemory.h"
#include "../Holon.h"

MemoryLong::MemoryLong(int memSize) :
  Memory(memSize)
{
  allocateMemory();
}

MemoryLong::~MemoryLong()
{
  delete []m_;
}

void MemoryLong::allocateMemory()
{
  if (m_) {
    delete []m_;
    m_ = nullptr;
  }
  if (memSize_ > 0)
  {
    m_ = new long[memSize_];
  }
}

void MemoryLong::attachDynamicValue(DynamicMemory* dm)
{
  Memory::attachDynamicValue(dm);
  v_ = &(dynamic_cast<ValueLong*>(dm)->v_);
}

void MemoryLong::recall(int index)
{
  if (index >= 0 && index < memSize_) {
    *v_ = m_[index];
  } else {
    throwIndexError(index, "recall");
  }
}

void MemoryLong::store(int index) 
{
  if (index >= 0 && index < memSize_) {
    m_[index] = *v_;
  } else {
    throwIndexError(index, "store");
  }
}

