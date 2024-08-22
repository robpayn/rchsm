/*
 * BehBoundFirstOrder.cpp
 */

#include "BehBoundFirstOrder.h"
#include "../../../Machine.h"
#include "RateFirstOrder.h"
#include "../../../CHSM/values/ValueDoubleMemory.h"

BehBoundFirstOrder::BehBoundFirstOrder(std::string soluteName) :
  soluteName_(soluteName)
{
  setNames();
}

void BehBoundFirstOrder::createVariables(Machine* machine, Holon* holon) {
  int phase = 1;
  machine->createVariable(
    rateName_, 
    new RateFirstOrder(phase, stateName_, coeffName_), 
    holon
  );
  machine->createVariable(coeffName_, new ValueDouble(), holon);
}

void BehBoundFirstOrder::createVariables(
    Machine* machine, 
    Holon* holon, 
    double initUptake
) 
{
  int phase = 1;
  machine->createVariable(
      rateName_, 
      new RateFirstOrder(phase, initUptake, stateName_, coeffName_), 
      holon
  );
}

void BehBoundFirstOrder::setNames()
{
  stateName_ = soluteName_ + stateSuffix_;
  rateName_ = soluteName_ + rateSuffix_;
  coeffName_ = soluteName_ + coeffSuffix_;
}
