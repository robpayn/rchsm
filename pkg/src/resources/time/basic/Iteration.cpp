/*
 * Iteration.cpp
 */

#include "Iteration.h"

Iteration::Iteration(int phase) :
  ValueLongMemory(phase)
{}

Iteration::Iteration(int phase, long init) :
  ValueLongMemory(phase, init)
{}

void Iteration::setDependencies(DepManager* dm) {}

void Iteration::update() {
  
  v_++;
  
}
