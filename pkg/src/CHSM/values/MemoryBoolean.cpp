/*
 * MemoryBoolean.cpp
 */

#include "MemoryBoolean.h"
#include "ValueBoolean.h"

MemoryBoolean::MemoryBoolean(int memSize) :
  Memory(memSize)
{
  allocateMemory();
}

MemoryBoolean::MemoryBoolean(ValueBoolean* value, int memSize) :
  Memory(memSize),
  val_(value)
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

Value* MemoryBoolean::getValue()
{
  return val_;
}

void MemoryBoolean::recall(int index)
{
  if (index >= 0 && index < memSize_) {
    val_->v_ = m_[index];
  } else {
    throwIndexError(index, "recall");
  }
}

void MemoryBoolean::setValue(Value* value)
{
  val_ = dynamic_cast <ValueBoolean*> (value);
}

void MemoryBoolean::store(int index) 
{
  if (index >= 0 && index < memSize_) {
    m_[index] = val_->v_;
  } else {
    throwIndexError(index, "store");
  }
}
