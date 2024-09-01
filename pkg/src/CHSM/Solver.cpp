/*
 * Solver.cpp
 */

#include "Solver.h"

Solver::Solver(double& timeStep) :
  timeStep_(timeStep)
{}

Solver::~Solver()
{}

void Solver::setDynamics(DepManager& dm)
{
  dynamics_.resize(dm.numPhases_);
  for(int phaseCount = 0; phaseCount < dm.numPhases_; phaseCount++) {
    dynamics_[phaseCount] = dm.sort(phaseCount);
  }
}
