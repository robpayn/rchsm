/*
 * Iteration.cpp
 */

#include "Iteration.h"

Iteration::Iteration() 
{
  phase_ = 0;
}

Iteration::Iteration(long init) :
  ValueLong(init)
{
  phase_ = 0;
}

void Iteration::setDependencies() {}

void Iteration::update() {
  
  int_++;
  
}
