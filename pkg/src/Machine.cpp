/*
 * Machine.cpp
 */

#include "Machine.h"
#include "Matrix.h"
#include "CHSM/Bound.h"
#include "CHSM/Cell.h"
#include "CHSM/values/ValueBoolean.h"
#include "CHSM/Rate.h"
#include "CHSM/Reporter.h"

#include <iostream>

// Constructors/Destructor

Machine::Machine(std::string name, DepManager* dm, Solver* solver) :
  Holon(name, new Matrix(dm, solver))
{};

Machine::~Machine() {
  
  for(Reporter* reporter : reporters_) {
    delete reporter;
  }
  
};

void Machine::init()
{

  Cell* cellTime = static_cast <Cell*> (getVariable("CellTime"));
  if (!cellTime) {
    throw std::runtime_error("Time cell with the name CellTime not found.");
  }
  
  Variable* timeValidVar = cellTime->getVariable("TimeValid");
  if (!timeValidVar) {
    throw std::runtime_error(
      "Time valid variable named TimeValid not found in time cell."
    );
  }
  timeValid_ = &(static_cast <ValueBoolean*> (timeValidVar->value_)->v_);
  
  getValue<Matrix>()->setDependencies(nullptr);
  
}

void Machine::installReporter(Reporter* reporter)
{
  reporters_.push_back(reporter);
  reporter->init(getValue<Matrix>());
}

void Machine::installVariable(Variable* variable, Holon* holon)
{
  holon->addVariable(variable);
  Dynamic* dynamic = dynamic_cast<Dynamic*>(variable->value_);
  if(dynamic) {
    getValue<Matrix>()->regDynamic(dynamic);
  }
  Rate* rate = dynamic_cast<Rate*>(variable->value_);
  if(rate) {
    rate->attachStates();
  }
}

Bound* Machine::createBound (
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

Cell* Machine::createCell (std::string name, Holon* holon) 
{
  Cell* cell = new Cell(name);
  
  if (holon) {
    holon->addVariable(cell);
  } else {
    addVariable(cell);
  }
  
  return cell;
}

Variable* Machine::createVariable(std::string name, Value* value, Holon* holon)
{
  Variable* variable = new Variable(name, value);
  installVariable(variable, holon);
  return variable;
}

void Machine::run()
{
  
  Matrix* matrix = getValue<Matrix>();

  for(Reporter* reporter : reporters_) {
    reporter->open();
  }
  
  for(Reporter* reporter : reporters_) {
    if(reporter->isActive()) {
      reporter->collectData();
      reporter->saveData();
    }
  }
  
  while(*timeValid_) {
    
    matrix->update();
    for(Reporter* reporter : reporters_) {
      if(reporter->isActive()) {
        reporter->collectData();
        reporter->saveData();
      }
    }
    
  }
  
  for(Reporter* reporter : reporters_) {
    reporter->close();
  }
  
}
