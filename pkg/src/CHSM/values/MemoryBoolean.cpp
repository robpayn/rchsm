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

MemoryBoolean::MemoryBoolean(ValueBoolean* value, int memSize) :
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
