/*
 * SolverForwardEuler.h
 */

#ifndef CHSM_SOLVERFORWARDEULER_H_
#define CHSM_SOLVERFORWARDEULER_H_

#include "Solver.h"

class SolverForwardEuler : public Solver
{
  public:
    
    static const std::vector<int> order_;
    
    SolverForwardEuler(double&);
    
    void update() override;
    
};

#endif /* CHSM_SOLVERFORWARDEULER_H_ */
