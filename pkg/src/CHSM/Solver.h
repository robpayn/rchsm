/*
 * Solver.h
 */

#ifndef CHSM_SOLVER_H_
#define CHSM_SOLVER_H_

#include "DepManager.h"
#include <vector>

class Dynamic;

class Solver
{
  public:
    
    std::vector<Dynamic*>* dynamics_ = nullptr;
    
    double& timeStep_ ;
    
    Solver(double&);
    
    virtual ~Solver();
    
    void setDynamics(DepManager&);
    
    virtual void solve() = 0;
    
};

#endif /* CHSM_SOLVER_H_ */
