/*
 * BehBoundDispersion.cpp
 */

#include "BehBoundDispersion.h"
#include "../../../Matrix.h"
#include "RateDispersion.h"

BehBoundDispersion::BehBoundDispersion(std::string soluteName) :
  soluteName_(soluteName)
{
  setNames();
}

void BehBoundDispersion::createVariables(
  Matrix* matrix, 
  Holon& holon, 
  double initDisp
) 
{
  int phase = 1;
  matrix->createVariable(
    rateName_, 
    new RateDispersion(initDisp, stateName_, coeffName_, phase), 
    holon
  );
}

void BehBoundDispersion::setNames()
{
  stateName_ = soluteName_ + stateSuffix_;
  rateName_ = soluteName_ + rateSuffix_;
  coeffName_ = soluteName_ + coeffSuffix_;
}
