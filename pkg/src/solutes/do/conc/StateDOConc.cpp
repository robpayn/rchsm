/*
 * StateDOConc.h
 */

#include "StateDOConc.h"

StateDOConc::StateDOConc(std::string name) :
  Variable(name)
{
  value_ = new ValueDouble();
}

void StateDOConc::update() 
{
  
}