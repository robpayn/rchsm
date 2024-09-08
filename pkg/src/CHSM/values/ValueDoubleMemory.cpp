/*
 * ValueDoubleMemory.cpp
 */

#include "ValueDoubleMemory.h"
#include "MemoryDouble.h"
#include "MemoryDoubleFactory.h"

ValueDoubleMemory::ValueDoubleMemory(
  double init,
  int phase
) :
  ValueDouble(init),
  DynamicMemory(phase)
{}
