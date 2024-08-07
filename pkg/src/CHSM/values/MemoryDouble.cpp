/*
 * MemoryDouble.cpp
 */

#include "MemoryDouble.h"
#include "ValueDouble.h"
#include "../Holon.h"

MemoryDouble::MemoryDouble(int memSize) :
  Memory(memSize)
{
  allocateMemory();
}

MemoryDouble::MemoryDouble(ValueDouble* value, int memSize) :
  Memory(memSize),
  val_(value)
{
  allocateMemory();
}

MemoryDouble::~MemoryDouble()
{
  delete []realm_;
}

void MemoryDouble::allocateMemory()
{
  if (realm_) {
    delete realm_;
    realm_ = nullptr;
  }
  if (memSize_ > 0)
  {
    realm_ = new double[memSize_];
  }
}

void MemoryDouble::recall(int index)
{
  if (index >= 0 && index < memSize_) {
    val_->real_ = realm_[index];
  } else {
    throwIndexError(index, "recall");
  }
}

void MemoryDouble::setValue(Value* value)
{
  val_ = dynamic_cast <ValueDouble*> (value);
}

void MemoryDouble::store(int index) 
{
  if (index >= 0 && index < memSize_) {
    realm_[index] = val_->real_;
  } else {
    throwIndexError(index, "store");
  }
}

void MemoryDouble::throwIndexError(int index, std::string mode) 
{
  std::ostringstream error;
  error << "Memory " << mode << " index value " << std::to_string(index) <<
    " is out of range for variable " << val_->var_->name_ <<
    " in holon " << val_->var_->holon_->name_ << ".";
  throw std::runtime_error(error.str());
}
