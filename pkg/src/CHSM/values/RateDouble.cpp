/*
 * RateDouble.cpp
 */

#include "RateDouble.h"

RateDouble::RateDouble(int phase) :
  ValueDouble(),
  Dynamic(phase)
{}

RateDouble::RateDouble(int phase, double initValue) :
  ValueDouble(initValue),
  Dynamic(phase)
{}

void RateDouble::setDependencies(DepManager* dm)
{}

void RateDouble::update()
{}
