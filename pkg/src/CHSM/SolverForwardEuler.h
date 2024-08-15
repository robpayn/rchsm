/*
 * SolverForwardEuler.h
 */

#ifndef CHSM_SOLVERFORWARDEULER_H_
#define CHSM_SOLVERFORWARDEULER_H_

#include "Solver.h"

class SolverForwardEuler : public Solver
{
  public:
    
    void solve() override;
    
};

#endif /* CHSM_SOLVERFORWARDEULER_H_ */
