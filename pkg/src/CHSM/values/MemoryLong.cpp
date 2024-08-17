/*
 * MemoryLong.cpp
 */

#include "MemoryLong.h"
#include "ValueLong.h"

MemoryLong::MemoryLong(int memSize) :
  Memory(memSize)
{
  allocateMemory();
}

MemoryLong::MemoryLong(ValueLong* value, int memSize) :
  Memory(memSize),
  val_(value)
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

Value* MemoryLong::getValue()
{
  return val_;
}

void MemoryLong::recall(int index)
{
  if (index >= 0 && index < memSize_) {
    val_->v_ = m_[index];
  } else {
    throwIndexError(index, "recall");
  }
}

void MemoryLong::setValue(Value* value)
{
  val_ = dynamic_cast <ValueLong*> (value);
}

void MemoryLong::store(int index) 
{
  if (index >= 0 && index < memSize_) {
    m_[index] = val_->v_;
  } else {
    throwIndexError(index, "store");
  }
}

