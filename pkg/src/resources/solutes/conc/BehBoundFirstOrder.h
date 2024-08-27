/*
 * BehBoundFirstOrder.h
 */

#ifndef RESOURCES_SOLUTES_CONC_BEHBOUNDFIRSTORDER_H_
#define RESOURCES_SOLUTES_CONC_BEHBOUNDFIRSTORDER_H_

#include <string>

class Matrix;
class Holon;

class BehBoundFirstOrder
{
public:
  
  std::string soluteName_ = "";
  
  std::string stateSuffix_ = "Conc";
  
  std::string stateName_ = "";
  
  std::string rateSuffix_ = "Rate";
  
  std::string rateName_ = "";
  
  std::string coeffSuffix_ = "RateCoeff";
  
  std::string coeffName_ = "";
  
  BehBoundFirstOrder(std::string);
  
  // Methods
  
  void createVariables(Matrix*, Holon&, double);
  
  void setNames();
  
};

#endif /* RESOURCES_SOLUTES_CONC_BEHBOUNDFIRSTORDER_H_ */
