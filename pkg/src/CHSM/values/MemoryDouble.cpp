/*
 * MemoryDouble.cpp
 */

#include "MemoryDouble.h"
#include "ValueDoubleMemory.h"
#include "../Holon.h"

MemoryDouble::MemoryDouble(int memSize) :
  Memory(memSize)
{
  allocateMemory();
}

MemoryDouble::MemoryDouble(ValueDoubleMemory* value, int memSize) :
  Memory(memSize),
  val_(value)
{
  allocateMemory();
  val_->attachMemory(this);
}

MemoryDouble::~MemoryDouble()
{
  delete []m_;
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

Value* MemoryDouble::getValue()
{
  return val_;
}

void MemoryDouble::recall(int index)
{
  if (index >= 0 && index < memSize_) {
    val_->v_ = m_[index];
  } else {
    throwIndexError(index, "recall");
  }
}

void MemoryDouble::setValue(Value* value)
{
  val_ = dynamic_cast <ValueDoubleMemory*> (value);
}

void MemoryDouble::store(int index) 
{
  if (index >= 0 && index < memSize_) {
    m_[index] = val_->v_;
  } else {
    throwIndexError(index, "store");
  }
}
