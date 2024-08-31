/*
 * RateDOER.cpp
 */

#include "RateDOER.h"

RateDOER::RateDOER(
  double initValue, 
  std::string stateName,
  int phase, 
  std::shared_ptr<MemoryFactory> mf
) :
  RateDouble(initValue, stateName, phase, mf)
{}

void RateDOER::setDependencies(DepManager& dm)
{}

void RateDOER::update()
{}