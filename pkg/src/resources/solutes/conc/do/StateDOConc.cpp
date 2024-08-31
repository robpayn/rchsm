/*
 * StateDOConc.h
 */

#include "StateDOConc.h"

StateDOConc::StateDOConc(
  double initValue,
  int phase, 
  std::shared_ptr<MemoryFactory> mf
) :
  StateDouble(initValue, phase, mf)
{}
