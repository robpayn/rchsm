/*
 * Iteration.cpp
 */

#include "Iteration.h"

Iteration::Iteration(int phase) :
  ValueLong(),
  Dynamic(phase)
{}

Iteration::Iteration(int phase, long init) :
  ValueLong(init),
  Dynamic(phase)
{}

void Iteration::setDependencies() {}

void Iteration::update() {
  
  v_++;
  
}
