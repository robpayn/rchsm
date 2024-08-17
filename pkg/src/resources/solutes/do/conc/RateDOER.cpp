/*
 * RateDOER.cpp
 */

#include "RateDOER.h"

RateDOER::RateDOER(int phase, std::string stateName) :
  RateDouble(phase, stateName)
{}

RateDOER::RateDOER(int phase, double initValue, std::string stateName) :
  RateDouble(phase, initValue, stateName)
{}

void RateDOER::setDependencies(DepManager* dm)
{}

void RateDOER::update()
{}