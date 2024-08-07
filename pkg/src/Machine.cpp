/*
 * Machine.cpp
 */

#include "Machine.h"
#include "Matrix.h"
#include "CHSM/Bound.h"
#include "CHSM/Cell.h"


// Constructors/Destructor

Machine::Machine(std::string name) :
  Holon(name, new Matrix())
{
  
  try {
    // Dynamic* time = dynamic_cast <Dynamic*> (
    //   timeCell->getVariable("Time")->value_
    // );
    // 
    // if (time) {
    //   time->setDependencies();
    // } else {
    //   throw std::runtime_error("Could not find time variable in time cell.\n");
    // }
  } catch (std::runtime_error &thrown) {
    std::ostringstream error;
    error << "Error in machine constructor:\n  " << thrown.what();
    throw std::runtime_error(error.str());
  }
  
};

Machine::~Machine() {};

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
