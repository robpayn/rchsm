/*
 * SolverForwardEuler.cpp
 */

#include "SolverForwardEuler.h"
#include "Dynamic.h"

SolverForwardEuler::SolverForwardEuler(double& timeStep) :
  Solver(timeStep)
{}

void SolverForwardEuler::solve()
{
  for(Dynamic* dyn : dynamics_[1]) {
    dyn->update();
  }
  
  for(Dynamic* dyn : dynamics_[2]) {
    dyn->update();
  }
  
  for(Dynamic* dyn : dynamics_[0]) {
    dyn->update();
  }
}
