/*
 * Iteration.cpp
 */

#include "Iteration.h"

Iteration::Iteration(long init, int phase, std::shared_ptr<MemoryFactory> mf) :
  ValueLongMemory(init, phase, mf)
{}

void Iteration::setDependencies(DepManager& dm) {}

void Iteration::update() {
  
  v_++;
  
}
