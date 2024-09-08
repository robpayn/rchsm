/*
 * RateDOGPP.cpp
 */

#include "RateDOGPP.h"

RateDOGPP::RateDOGPP(
  double initValue, 
  std::string stateName,
  int phase
) :
  RateDouble(initValue, 0, stateName, phase)
{}

void RateDOGPP::setDependencies(DepManager& dm)
{}

void RateDOGPP::update()
{}