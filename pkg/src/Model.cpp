/*
 * Model.cpp
 */

#include "Model.h"

// Constructors/Destructor

Model::Model(std::string name) :
  Holon(name)
{
  try {
    Cell* timeCell = createCell("CellTime", nullptr);
    Bound* timeBound = createBound("BoundTime", nullptr, timeCell, nullptr);
    
    behCellTime_ = BehCellTime();
    behCellTime_.createVariables(timeCell);

    behBoundTime_ = BehBoundTime();
    behBoundTime_.createVariables(timeBound);

    Dynamic* time = dynamic_cast <Dynamic*> (
      timeCell->getVariable("Time")->value_
    );

    if (time) {
      time->setDependencies();
    } else {
      throw std::runtime_error("Could not find time variable in time cell.\n");
    }
  } catch (std::runtime_error &thrown) {
    std::ostringstream error;
    error << "Error in model constructor:\n  " << thrown.what();
    throw std::runtime_error(error.str());
  }
};

Model::~Model() {};

// Methods

Cell* Model::createCell (std::string name, Holon* holon) 
{
  
  Cell* cell = new Cell(name);
  
  if (holon) {
    holon->addVariable(cell);
  } else {
    addVariable(cell);
  }
  
  return cell;
  
}

Bound* Model::createBound (
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
