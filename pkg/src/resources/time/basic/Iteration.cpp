/*
 * Iteration.cpp
 */

#include "Iteration.h"

Iteration::Iteration(long init, int phase) :
  ValueLongMemory(init, phase)
{}

void Iteration::setDependencies(DepManager& dm) {}

void Iteration::update() {
  
  v_++;
  
}
