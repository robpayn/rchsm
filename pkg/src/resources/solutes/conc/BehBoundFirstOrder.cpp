/*
 * BehBoundFirstOrder.cpp
 */

#include "BehBoundFirstOrder.h"
#include "../../../Matrix.h"
#include "RateFirstOrder.h"

BehBoundFirstOrder::BehBoundFirstOrder(std::string soluteName) :
  soluteName_(soluteName)
{
  setNames();
}

void BehBoundFirstOrder::createVariables(
  Matrix* matrix, 
  Holon& holon, 
  double initUptake
) 
{
  int phase = 1;
  matrix->createVariable(
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
