/*
 * SolverRKTwo.h
 */

#ifndef CHSM_SOLVERRKTWO_H_
#define CHSM_SOLVERRKTWO_H_

#include "Solver.h"
#include "Memory.h"

class SolverRKTwo : public Solver
{
  public:
    
    std::vector<Memory*> memories_;
    
    SolverRKTwo(double&);
    
    virtual ~SolverRKTwo();
    
    void setDependencies(DepManager&) override;
    
    void update() override;
  
};


#endif /* CHSM_SOLVERRKTWO_H_ */
