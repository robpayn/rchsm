/*
 * RateDOGPP.cpp
 */

#include "RateDOGPP.h"

RateDOGPP::RateDOGPP(int phase, std::string stateName) :
  RateDouble(phase, stateName)
{}

RateDOGPP::RateDOGPP(int phase, double initValue, std::string stateName) :
  RateDouble(phase, initValue, stateName)
{}

void RateDOGPP::setDependencies(DepManager* dm)
{}

void RateDOGPP::update()
{}