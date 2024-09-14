/*
 * BehBoundAdvection.cpp
 */

#include "BehBoundAdvection.h"
#include "../../../Matrix.h"
#include "RateAdvection.h"

BehBoundAdvection::BehBoundAdvection(std::string soluteName) :
  soluteName_(soluteName)
{
  setNames();
}

void BehBoundAdvection::createVariables(
  Matrix* matrix, 
  Holon& holon, 
  double initDisp
) 
{
  int phase = 1;
  matrix->createVariable(
    rateName_, 
    new RateAdvection(initDisp, stateName_, velocityName_, phase), 
    holon
  );
}

void BehBoundAdvection::setNames()
{
  stateName_ = soluteName_ + stateSuffix_;
  rateName_ = soluteName_ + rateSuffix_;
}
