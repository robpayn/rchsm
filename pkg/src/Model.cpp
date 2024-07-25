/*
 * Model.cpp
 */

#include "Model.h"
#include <iostream>

// Constructors/Destructor

Model::Model(std::string name) :
  Variable(name),
  Holon(name)
{};

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
  catch (std::string error) {
    std::cerr << "Error in creating the bound:\n  " << error;
    return nullptr;
  }

}

void Model::update() {};
