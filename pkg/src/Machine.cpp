/*
 * Machine.cpp
 */

#include "Machine.h"
#include "Matrix.h"
#include "CHSM/Bound.h"
#include "CHSM/Cell.h"
#include "CHSM/values/ValueBoolean.h"
#include "CHSM/Reporter.h"

#include <iostream>

// Constructors/Destructor

Machine::Machine(std::string name, Matrix* matrix) :
  Holon(name, matrix)
{};

Machine::~Machine() 
{
  for(Reporter* reporter : reporters_) {
    delete reporter;
  }
};

void Machine::installReporter(Reporter* reporter)
{
  reporters_.push_back(reporter);
}

void Machine::run()
{
  
  Matrix* matrix = getValue<Matrix>();
  matrix->setDependencies();

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

void Machine::setTimeValidVariable(Variable* var)
{
  ValueBoolean* val = dynamic_cast<ValueBoolean*>(var->value_);
  if(val) {
    timeValid_ = &(val->v_);
  } else {
    std::ostringstream error;
    error << "Error in setting the time valid variable for the state machine. "
      << "Variable " << var->name_ << " does not have a boolean value.";
    throw std::runtime_error(error.str());
  }
    
}