/*
 * BehBoundFirstOrder.h
 */

#ifndef RESOURCES_SOLUTES_CONC_BEHBOUNDFIRSTORDER_H_
#define RESOURCES_SOLUTES_CONC_BEHBOUNDFIRSTORDER_H_

#include "../../../CHSM/Behavior.h"
#include <string>

class BehBoundFirstOrder : public Behavior
{
public:
  
  std::string soluteName_ = "";
  
  std::string stateSuffix_ = "Conc";
  
  std::string stateName_ = "";
  
  std::string rateSuffix_ = "Uptake";
  
  std::string rateName_ = "";
  
  std::string coeffSuffix_ = "RateCoeff";
  
  std::string coeffName_ = "";
  
  BehBoundFirstOrder(std::string);
  
  // Methods
  
  void createVariables(Machine*, Holon*) override;
  
  void createVariables(Machine*, Holon*, double, double);
  
  void setNames();
  
};

#endif /* RESOURCES_SOLUTES_CONC_BEHBOUNDFIRSTORDER_H_ */
