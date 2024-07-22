/*
 * DOConcCell.h
 */

#include "DOConcCell.h"

DOConcCell::DOConcCell(std::string name) :
  Variable(name)
{
  value_ = new ValueDouble();
}

void DOConcCell::update() 
{
  
}