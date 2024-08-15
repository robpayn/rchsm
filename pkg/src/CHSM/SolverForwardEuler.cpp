/*
 * SolverFowardEuler.cpp
 */

#include "SolverForwardEuler.h"
#include "Dynamic.h"

void SolverForwardEuler::solve()
{
  
  for(Dynamic* dyn : dynamics_[0]) {
    dyn->update();
  }
  
}
