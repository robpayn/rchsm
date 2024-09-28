/*
 * MemoryBoolean.cpp
 */

#include "MemoryBoolean.h"
#include "ValueBoolean.h"
#include "../DynamicMemory.h"
#include "../Holon.h"
#include <sstream>

MemoryBoolean::MemoryBoolean(int memSize) :
  Memory(memSize)
{
  allocateMemory();
}

MemoryBoolean::~MemoryBoolean()
{
  delete []m_;
}

void MemoryBoolean::allocateMemory()
{
  if (m_) {
    delete []m_;
    m_ = nullptr;
  }
  if (memSize_ > 0)
  {
    m_ = new bool[memSize_];
  }
}

void MemoryBoolean::attachDynamicValue(DynamicMemory* dm)
{
  Memory::attachDynamicValue(dm);
  v_ = &(dynamic_cast<ValueBoolean*>(val_)->v_);
}

void MemoryBoolean::recall(int index)
{
  if (index >= 0 && index < memSize_) {
    *v_ = m_[index];
  } else {
    throwIndexError(index, "recall");
  }
}

void MemoryBoolean::store(int index) 
{
  if (index >= 0 && index < memSize_) {
    m_[index] = *v_;
  } else {
    throwIndexError(index, "store");
  }
}
