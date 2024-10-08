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

MemoryLong::MemoryLong(ValueLong* value, int memSize) :
  Memory(memSize),
  val_(value)
{
  allocateMemory();
  DynamicMemory* dm = dynamic_cast<DynamicMemory*>(val_);
  if(dm) {
    dm->attachMemory(this);
  } else {
    std::ostringstream error;
    error << "Memory cannot be attached to value of " << val_->var_->name_
          << " because it does not implement dynamic memory.";
    throw std::runtime_error(error.str());
  }
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

