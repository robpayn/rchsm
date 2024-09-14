/*
 * BehBoundAdvection.h
 */

#ifndef RESOURCES_SOLUTES_CONC_BEHBOUNDADVECTION_H_
#define RESOURCES_SOLUTES_CONC_BEHBOUNDADVECTION_H_

#include <string>

class Matrix;
class Holon;

class BehBoundAdvection
{
public:
  
  std::string soluteName_ = "";
  
  std::string stateSuffix_ = "Conc";
  
  std::string stateName_ = "";
  
  std::string rateSuffix_ = "Advection";
  
  std::string rateName_ = "";
  
  std::string velocityName_ = "WaterVelocity";
  
  BehBoundAdvection(std::string);
  
  // Methods
  
  void createVariables(Matrix*, Holon&, double);
  
  void setNames();
  
};

#endif /* RESOURCES_SOLUTES_CONC_BEHBOUNDADVECTION_H_ */
