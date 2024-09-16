/*
 * Iteration.cpp
 */

#include "Iteration.h"

Iteration::Iteration(long init, int phase) :
  ValueLong(init),
  DynamicMemory(phase)
{}

void Iteration::setDependencies(DepManager& dm) {}

void Iteration::update() {
  
  v_++;
  
}
