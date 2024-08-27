/*
 * Solver.cpp
 */

#include "Solver.h"

Solver::Solver(double& timeStep) :
  timeStep_(timeStep)
{}

Solver::~Solver()
{
  delete []dynamics_;
}

void Solver::setDynamics(DepManager& dm)
{
  dynamics_ = new std::vector<Dynamic*>[dm.numPhases_];
  for(int phase = 0; phase < dm.numPhases_; phase++) {
    dynamics_[phase] = dm.sort(phase);
  }
}
