/*
 * Machine.cpp
 */

#include "Machine.h"
#include "Matrix.h"
#include "CHSM/Bound.h"
#include "CHSM/Cell.h"
#include "CHSM/values/ValueBoolean.h"

#include <iostream>

// Constructors/Destructor

Machine::Machine(std::string name) :
  Holon(name, new Matrix())
{};

Machine::~Machine() {};

void Machine::init()
{
  Matrix* matrix = static_cast <Matrix*> (value_);
  Cell* cellTime = static_cast <Cell*> (getVariable("CellTime"));
  if (!cellTime) {
    throw std::runtime_error("Time cell with the name CellTime not found.");
  }
  
  Variable* timeVar = cellTime->getVariable("Time");
  if (!timeVar) {
    throw std::runtime_error(
      "Time variable with the name Time not found in time cell."
    );
  }
  Dynamic* time = dynamic_cast <Dynamic*> (timeVar->value_);
  if (!time) {
    throw std::runtime_error("Time value is not dynamic.");
  }
  matrix->setTime(time);
  
  Variable* timeValidVar = cellTime->getVariable("TimeValid");
  if (!timeValidVar) {
    throw std::runtime_error(
      "Time valid variable named TimeValid not found in time cell."
    );
  }
  timeValid_ = &(static_cast <ValueBoolean*> (timeValidVar->value_)->v_);
  
  matrix->setDependencies();
}

void Machine::installVariable(Variable* variable, Holon* holon)
{
  holon->addVariable(variable);
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
  Matrix* matrix = static_cast <Matrix*> (value_);
  
  matrix->time_->update();
  while(*timeValid_) {
    
    matrix->update();
    
  }
}
