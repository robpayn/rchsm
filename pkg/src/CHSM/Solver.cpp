/*
 * Solver.cpp
 */

#include "Solver.h"
#include "../Matrix.h"

#include <exception>

Solver::Solver(double& timeStep) :
  Updater(-1),
  timeStep_(timeStep)
{}

Solver::~Solver()
{}

void Solver::setDependencies(DepManager& dm) 
{
  dm.manageDependencies();
  updaters_.resize(dm.numPhases_);
  for(int phaseCount = 0; phaseCount < dm.numPhases_; phaseCount++) {
    updaters_[phaseCount] = dm.sort(phaseCount);
  }
}
