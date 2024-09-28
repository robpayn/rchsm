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
  Updater(phase)
{}

void IterationUpdater::setDependencies(DepManager& dm) 
{
  v_ = &(static_cast<ValueLong*>(val_)->v_);  
}

void IterationUpdater::update() 
{
  (*v_)++;
}
