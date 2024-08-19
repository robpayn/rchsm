/*
 * BehCellSolute.h
 */

#ifndef RESOURCES_SOLUTES_CONC_BEHCELLSOLUTE_H_
#define RESOURCES_SOLUTES_CONC_BEHCELLSOLUTE_H_

#include "../../../CHSM/Behavior.h"
#include <string>

class BehCellSolute : public Behavior
{
public:
  
  std::string soluteName_ = "";
  
  std::string stateSuffix_ = "Conc";
  
  std::string stateName_ = "";
  
  BehCellSolute(std::string);
  
  // Methods
  
  void createVariables(Machine*, Holon*) override;
  
  void createVariables(Machine*, Holon*, double);
  
  void setNames();
  
};

#endif /* RESOURCES_SOLUTES_CONC_BEHCELLSOLUTE_H_ */
