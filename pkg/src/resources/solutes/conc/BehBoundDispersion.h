/*
 * BehBoundDispersion.h
 */

#ifndef RESOURCES_SOLUTES_CONC_BEHBOUNDDISPERSION_H_
#define RESOURCES_SOLUTES_CONC_BEHBOUNDDISPERSION_H_

#include <string>

class Matrix;
class Holon;

class BehBoundDispersion
{
public:
  
  std::string soluteName_ = "";
  
  std::string stateSuffix_ = "Conc";
  
  std::string stateName_ = "";
  
  std::string rateSuffix_ = "Dispersion";
  
  std::string rateName_ = "";
  
  std::string coeffSuffix_ = "DispCoeff";
  
  std::string coeffName_ = "";
  
  BehBoundDispersion(std::string);
  
  // Methods
  
  void createVariables(Matrix*, Holon&, double);
  
  void setNames();
  
};

#endif /* RESOURCES_SOLUTES_CONC_BEHBOUNDDISPERSION_H_ */
