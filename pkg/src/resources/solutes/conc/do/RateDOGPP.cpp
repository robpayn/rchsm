/*
 * RateDOGPP.cpp
 */

#include "RateDOGPP.h"

RateDOGPP::RateDOGPP(
  double initValue, 
  std::string stateName,
  int phase, 
  std::shared_ptr<MemoryFactory> mf
) :
  RateDouble(initValue, stateName, phase, mf)
{}

void RateDOGPP::setDependencies(DepManager& dm)
{}

void RateDOGPP::update()
{}