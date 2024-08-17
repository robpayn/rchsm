/*
 * Matrix.cpp
 */

#include "Matrix.h"
#include "CHSM/Bound.h"
#include "CHSM/values/ValueDouble.h"
#include "CHSM/DepManInstallOrder.h"
#include "CHSM/SolverForwardEuler.h"

//DEBUG CODE
// #include <iostream>

Matrix::Matrix(DepManager* dm, Solver* solver) :
  ValueVarmap(),
  Dynamic(-1),
  dm_(dm),
  solver_(solver)
{}

Matrix::~Matrix()
{
  delete dm_;
  delete solver_;
}

void Matrix::regDynamic(Dynamic* dynamic) {
  if (dynamic->phase_ >= 0) {
    dm_->addDynamic(dynamic);
    // DEBUG CODE
    // std::cerr << dynamic->phase_ << ":" << dm_->size(dynamic->phase_) << ",";
  }
}

void Matrix::setDependencies(DepManager* dm) {

  dm_->manageDependencies();
  solver_->setDynamics(dm_);
  
  Bound* bound = dynamic_cast<Bound*>(getVariable("BoundTime"));
  if(!bound) {
    std::ostringstream error;
    error << "Matrix could not find the BoundTime bound.";
    throw error.str();
  }

  ValueDouble* val = bound->getVarValue<ValueDouble>("TimeStep");
  if(val) {
    solver_->setTimeStep(&(val->v_));
  } else {
    std::ostringstream error;
    error << "Matrix could not find the TimeStep variable.";
    throw error.str();
  };
  
}

void Matrix::update() {
  
  solver_->solve();
  
}
