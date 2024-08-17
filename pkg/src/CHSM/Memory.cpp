/*
 * Memory.cpp
 */

#include "Memory.h"
#include "Value.h"
#include "Holon.h"
#include <sstream>

Memory::Memory(int memSize) :
  memSize_(memSize)
{}

void Memory::throwIndexError(int index, std::string mode) 
{
  std::ostringstream error;
  error << "Memory " << mode << " index value " << std::to_string(index) <<
    " is out of range for variable " << getValue()->var_->name_ <<
    " in holon " << getValue()->var_->holon_->name_ << ".";
  throw std::runtime_error(error.str());
}
