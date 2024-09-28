/*
 * MemoryDouble.cpp
 */

#include "MemoryDouble.h"
#include "ValueDouble.h"
#include "../DynamicMemory.h"
#include "../Holon.h"

MemoryDouble::MemoryDouble(int memSize) :
  Memory(memSize)
{
  allocateMemory();
}

MemoryDouble::~MemoryDouble()
{
  delete []m_;
}

void MemoryDouble::attachDynamicValue(DynamicMemory* dm)
{
  Memory::attachDynamicValue(dm);
  v_ = &(dynamic_cast<ValueDouble*>(val_)->v_);
}

void MemoryDouble::allocateMemory()
{
  if (m_) {
    delete []m_;
    m_ = nullptr;
  }
  if (memSize_ > 0)
  {
    m_ = new double[memSize_];
  }
}

void MemoryDouble::recall(int index)
{
  if (index >= 0 && index < memSize_) {
    *v_ = m_[index];
  } else {
    throwIndexError(index, "recall");
  }
}

void MemoryDouble::store(int index) 
{
  if (index >= 0 && index < memSize_) {
    m_[index] = *v_;
  } else {
    throwIndexError(index, "store");
  }
}
