/*
 * StateDOConc.h
 */

#include "StateDOConc.h"

StateDOConc::StateDOConc(int phase) :
  StateDouble(phase)
{}

StateDOConc::StateDOConc(int phase, double initValue) :
  StateDouble(phase, initValue)
{}
