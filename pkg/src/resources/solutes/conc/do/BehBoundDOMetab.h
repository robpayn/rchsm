/*
 * BehBoundDOMetab.h
 */

#ifndef RESOURCES_SOLUTES_DO_CONC_BEHBOUNDDOMETAB_H_
#define RESOURCES_SOLUTES_DO_CONC_BEHBOUNDDOMETAB_H_

#include "../../../../CHSM/Behavior.h"

class BehBoundDOMetab : public Behavior
{
public:
  
  // Methods
  
  void createVariables(Machine*, Holon*) override;
  
  void createVariables(Machine*, Holon*, double, double);
  
};

#endif /* RESOURCES_SOLUTES_DO_CONC_BEHBOUNDDOMETAB_H_ */
