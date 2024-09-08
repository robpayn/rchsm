/*
 * RateDOER.cpp
 */

#include "RateDOER.h"

RateDOER::RateDOER(
  double initValue, 
  std::string stateName,
  int phase
) :
  RateDouble(initValue, 0, stateName, phase)
{}

void RateDOER::setDependencies(DepManager& dm)
{}

void RateDOER::update()
{}