/*
 * SolverRKTwo.cpp
 */

#include "SolverRKTwo.h"
#include "DynamicMemory.h"
#include "MemoryFactory.h"

SolverRKTwo::SolverRKTwo(double& timeStep) :
  Solver(timeStep)
{}

SolverRKTwo::~SolverRKTwo()
{}

void SolverRKTwo::setDependencies(DepManager& dm)
{
  Solver::setDependencies(dm);
  
  memories_.resize(updaters_[2].size());
  long memCount = 0;
  for(Updater* updater : updaters_[2]) {
    DynamicMemory* dm = dynamic_cast<DynamicMemory*>(updater->val_);
    Value* val = dynamic_cast<Value*>(updater->val_);
    if(dm && val && dm->memory_) {
      memories_[memCount] = dm->memory_;
    } else {
      std::ostringstream error;
      error << "Cannot create a memory. The second order Runge Kutta "
        << "solver must be able to install memory on values in the "
        << "state phase.";
      throw std::runtime_error(error.str());
    }
    memCount++;
  }
}

void SolverRKTwo::update()
{
  // Calculate the rates at the beginning of the time step
  for(Updater* updater : updaters_[1]) {
    updater->update();
  }
  
  // Remember the state phase at the beginning of the time step
  for(Memory* mem : memories_) {
    mem->store(0);
  }
  // Based on the rates at the beginning of the time step,
  // estimate the rates at halfway through the time step
  double origTimeStep = timeStep_;
  timeStep_ = timeStep_ / 2;
  for(Updater* updater : updaters_[2]) {
    updater->update();
  }
  for(Updater* updater : updaters_[1]) {
    updater->update();
  }

  // Recall the state phase at the beginning of the time step,
  // and recalculate the change of state over the full time step based on the 
  // estimates of the rates halfway through the time step
  for(Memory* mem : memories_) {
    mem->recall(0);
  }
  timeStep_ = origTimeStep;
  for(Updater* updater : updaters_[2]) {
    updater->update();
  }
  
  // Calculate the time values
  for(Updater* updater : updaters_[0]) {
    updater->update();
  }
}
