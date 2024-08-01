/*
 * StateDOConc.h
 */

#include "StateDOConc.h"

StateDOConc::StateDOConc(std::string name) :
  Variable(name)
{
  value_ = new ValueDouble();
  phase_ = 2;
}

void StateDOConc::setDependencies() {}

void StateDOConc::update() {}
