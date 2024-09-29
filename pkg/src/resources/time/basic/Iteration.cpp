/*
 * Iteration.cpp
 */

#include "Iteration.h"

Iteration::Iteration(long initValue, int phase) :
  ValueLong(initValue)
{
  attachUpdater(new IterationUpdater(phase));
}

IterationUpdater::IterationUpdater(int phase) :
  UpdaterLong(phase)
{}

void IterationUpdater::setDependencies(DepManager& dm) 
{}

void IterationUpdater::update() 
{
  (*v_)++;
}
