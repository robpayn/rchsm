/*
 * SolverForwardEuler.cpp
 */

#include "SolverForwardEuler.h"
#include "Dynamic.h"

const std::vector<int> SolverForwardEuler::order_ = {1, 2, 0};

SolverForwardEuler::SolverForwardEuler(double& timeStep) :
  Solver(timeStep)
{}

void SolverForwardEuler::solve()
{
  for(int index : order_) {
    for(Dynamic* dyn : dynamics_[index]) {
      dyn->update();
    }
  }
}
