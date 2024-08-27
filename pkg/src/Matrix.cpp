/*
 * Matrix.cpp
 */

#include "Matrix.h"
#include "CHSM/Bound.h"
#include "CHSM/Cell.h"
#include "CHSM/DepManager.h"
#include "CHSM/Solver.h"
#include "CHSM/values/ValueDouble.h"
#include "CHSM/Rate.h"

Matrix::Matrix(DepManager* dm) :
  ValueVarmap(),
  Dynamic(-1),
  dm_(dm)
{}

Matrix::~Matrix()
{
  delete dm_;
  delete solver_;
}

Bound* Matrix::createBound (
  std::string name, 
  Cell* cellFrom, 
  Cell* cellTo, 
  Holon* holon
) 
{
  try {
    Bound* bound = new Bound(name, cellFrom, cellTo);
    
    if (holon) {
      holon->addVariable(bound);
    } else {
      addVariable(bound);
    }
    
    return bound;
  }
  catch (std::runtime_error &thrown) {
    std::ostringstream error;
    error << "Error in creating the bound:\n  " << thrown.what();
    throw error;
  }
}

Cell* Matrix::createCell(std::string name, Holon* holon) 
{
  Cell* cell = new Cell(name);
  
  if (holon) {
    holon->addVariable(cell);
  } else {
    addVariable(cell);
  }
  
  return cell;
}

Variable* Matrix::createVariable(std::string name, Value* value, Holon& holon)
{
  Variable* variable = new Variable(name, value);
  installVariable(variable, holon);
  return variable;
}

void Matrix::installSolver(Solver* solver)
{
  solver_ = solver;
}

void Matrix::installVariable(Variable* variable, Holon& holon)
{
  holon.addVariable(variable);
  
  Dynamic* dynamic = dynamic_cast<Dynamic*>(variable->value_);
  if(dynamic && (dynamic->phase_ >= 0)) {
    dm_->addDynamic(dynamic);
  }
  
  Rate* rate = dynamic_cast<Rate*>(variable->value_);
  if(rate) {
    rate->attachStates();
  }
}

void Matrix::setDependencies()
{
  setDependencies(*dm_);
}

void Matrix::setDependencies(DepManager& dm) 
{
  dm.manageDependencies();
  solver_->setDynamics(dm);
}

void Matrix::update() 
{
  solver_->solve();
}
