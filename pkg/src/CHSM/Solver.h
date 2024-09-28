/*
 * Solver.h
 */

#ifndef CHSM_SOLVER_H_
#define CHSM_SOLVER_H_

#include "Updater.h"
#include "DepManager.h"
#include <vector>

class Matrix;

class Solver : public Updater
{
  public:
    
    std::vector<std::vector<Updater*>> updaters_;
    
    double& timeStep_ ;
    
    Solver(double&);
    
    virtual ~Solver();
    
    /*!
     \brief
     Set the dependencies of the matrix using the provided dependency
     manager.
     
     \param DepManager&
     Reference to the dependency manager that should be notified of
     critical dependencies.
     
     \return
     No return value
     */
    virtual void setDependencies(DepManager&) override;
    
};

#endif /* CHSM_SOLVER_H_ */
